/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#include "MotionBusinnessLogic.hpp"

namespace istvan_richard
{
    void CMotionBusinnessLogic::fUpdateMotionLogic()
    {
        if (m_motionCommInfo_r.fGetMovementDetected())
        {
            if (m_motionCommInfo_r.fGetMovementSize() >= m_motionDetectParam_r.fGetNormalTimeWarningThreshold())
            {
                if (m_motionCommInfo_r.fGetConfidenceInMovement() >= 80
                    && fIsInValidTime())
                {
                    //Set Normal Warn
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::WARNING_IN_TIME);
                }
                else
                {
                    //Set SUS
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::SUS);
                }
            }
            else if (m_motionCommInfo_r.fGetMovementSize() >= m_motionDetectParam_r.fGetOutOfNormalTimeWarningThreshold())
            {

                if (m_motionCommInfo_r.fGetConfidenceInMovement() >= 80
                    && !fIsInValidTime())
                {
                    //Set Out Of time Warn
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::WARNING_OUT_OG_TIME);
                }
                else
                {
                    //Set Sus
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::SUS);
                }
            }
        }
        else
        {
            //No movement -> All_OK
            m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::ALL_OK);
        }
    }

    bool CMotionBusinnessLogic::fIsInValidTime()
    {
        bool l_isLaterThanStart_b(false);
        bool l_isEarlierThanEnd_b(false);
        for (auto l_it_p = m_motionDetectParam_r.fGetStartOfMonitoring().fGetDaysVector().begin();
            l_it_p != m_motionDetectParam_r.fGetStartOfMonitoring().fGetDaysVector().begin();
            l_it_p++)
        {
            if (l_it_p->fGetDay() == std::string("ALL")
                || l_it_p->fGetDay() == m_TimeStamp_r.fGetCurrentTime().fGetDay())
            {
                if (l_it_p->fGetHour() <= m_TimeStamp_r.fGetCurrentTime().fGetHour()
                    && l_it_p->fGetMinute() <= m_TimeStamp_r.fGetCurrentTime().fGetMinute()
                    && l_it_p->fGetSec() <= m_TimeStamp_r.fGetCurrentTime().fGetSec())
                {
                    l_isLaterThanStart_b = true;
                    break;
                }
                else
                {
                    l_isLaterThanStart_b = false;
                }
            }
            else
            {
                //let for run
            }
        }
        for (auto l_it_p = m_motionDetectParam_r.fGetEndOfMonitoring().fGetDaysVector().begin();
            l_it_p != m_motionDetectParam_r.fGetEndOfMonitoring().fGetDaysVector().begin();
            l_it_p++)
        {
            if (l_it_p->fGetDay() == std::string("ALL")
                || l_it_p->fGetDay() == m_TimeStamp_r.fGetCurrentTime().fGetDay())
            {
                if (l_it_p->fGetHour() >= m_TimeStamp_r.fGetCurrentTime().fGetHour()
                    && l_it_p->fGetMinute() >= m_TimeStamp_r.fGetCurrentTime().fGetMinute()
                    && l_it_p->fGetSec() >= m_TimeStamp_r.fGetCurrentTime().fGetSec())
                {
                    l_isLaterThanStart_b = true;
                    break;
                }
                else
                {
                    l_isLaterThanStart_b = false;
                }
            }
            else
            {
                //let for run
            }
        }
        if (l_isEarlierThanEnd_b && l_isLaterThanStart_b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}//end of namespace