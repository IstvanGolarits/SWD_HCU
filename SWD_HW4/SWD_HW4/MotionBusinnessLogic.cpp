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
            if (fIsInValidTime(m_motionDetectParam_r.fGetNormalTimeWarningThreshold()))
            {
                if (m_motionCommInfo_r.fGetConfidenceInMovement() >= 80 && m_motionCommInfo_r.fGetMovementSize() >= 0.6)
                {
                    //Movement in time-frame ->> Granny alive!
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::ALL_OK);
                }
                else
                {
                    //Potential Movement in time-frame ->> Granny may be alive!
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::SUS);
                }
            }
            else
            {
                if (m_motionCommInfo_r.fGetConfidenceInMovement() >= 80 && m_motionCommInfo_r.fGetMovementSize() >= 0.6)
                {
                    //THERE IS AN INTRUDER!!!
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::WARNING_OUT_OF_TIME);
                }
                else
                {
                    //There might be an intruder!
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::SUS);
                }
            }
        }
        else
        {
            // negating value of param, as here we are looking for an outer scope (enlonged timeframe).
            if (fIsInValidTime((-1)*m_motionDetectParam_r.fGetOutOfNormalTimeWarningThreshold()))
            {
                    //No Movement in time-fram -> Granny might be in trubble!
                    m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::WARNING_IN_TIME);
            }
            else
            {
                //There is no intruder in grannys house.
                m_MotionToSysInfo_r.fUpdateState(CMotion2SysInfo::E_StateOfMotionBussiness::ALL_OK);
            }
        }
    }

    void CMotionBusinnessLogic::fCheckForMotion()
    {
        if (m_motionCommInfo_r.fGetMovementDetected())
        {
            if (!m_WasAlreadyMoveDetect_b)
            {
                m_WasAlreadyMoveDetect_b = true;
                m_StartOfMovement = m_TimeStamp_r.fGetCurrentTime();
            }
        }
        else
        {
            if (m_WasAlreadyMoveDetect_b)
            {
                m_StartOfMovement = { std::string(" "), 0, 0, 0 };
                m_WasAlreadyMoveDetect_b = false;
            }
        }
    }

    bool CMotionBusinnessLogic::fIsBeforeStartTime(const float& f_thresholdValue_r)
    {
        for (auto l_it_p = m_motionDetectParam_r.fGetEndOfMonitoring().fGetDaysVector().begin();
            l_it_p != m_motionDetectParam_r.fGetEndOfMonitoring().fGetDaysVector().end();
            l_it_p++)
        {
            if (l_it_p->fGetDay() == std::string("ALL")
                || l_it_p->fGetDay() == m_TimeStamp_r.fGetCurrentTime().fGetDay())
            {
                if (l_it_p->fGetHour() >= m_TimeStamp_r.fGetCurrentTime().fGetHour()
                    && l_it_p->fGetMinute() >= (m_TimeStamp_r.fGetCurrentTime().fGetMinute() + f_thresholdValue_r)
                    && l_it_p->fGetSec() >= m_TimeStamp_r.fGetCurrentTime().fGetSec())
                {
                    return true;
                }
                else
                {
                    //
                }
            }
            else
            {
                //
            }
        }
        return false;
    }

    bool CMotionBusinnessLogic::fIsAfterEndTime(const float& f_thresholdValue_r)
    {
        for (auto l_it_p = m_motionDetectParam_r.fGetEndOfMonitoring().fGetDaysVector().begin();
            l_it_p != m_motionDetectParam_r.fGetEndOfMonitoring().fGetDaysVector().end();
            l_it_p++)
        {
            if (l_it_p->fGetDay() == std::string("ALL")
                || l_it_p->fGetDay() == m_TimeStamp_r.fGetCurrentTime().fGetDay())
            {
                if (l_it_p->fGetHour() <= m_TimeStamp_r.fGetCurrentTime().fGetHour()
                    && l_it_p->fGetMinute() <= (m_TimeStamp_r.fGetCurrentTime().fGetMinute() - f_thresholdValue_r)
                    && l_it_p->fGetSec() <= m_TimeStamp_r.fGetCurrentTime().fGetSec())
                {
                    return true;
                }
                else
                {
                    //
                }
            }
            else
            {
                //
            }
        }
        return false;
    }

    bool CMotionBusinnessLogic::fIsInValidTime(const float& f_thresholdValue_r)
    {
        if (!fIsAfterEndTime(f_thresholdValue_r) && !fIsBeforeStartTime(f_thresholdValue_r))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}//end of namespace