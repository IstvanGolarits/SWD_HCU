/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: Deciding if a warning shall be requested based on sensor input, time, and user-defined setups
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

    bool CMotionBusinnessLogic::fIsBeforeStartTime(const float& f_thresholdValue_r)
    {
        auto l_startTimeForDay(m_motionDetectParam_r.fGetStartOfMonitoring().fGetCurrentDaySetup(m_TimeStamp_r));
        DailyDateTime l_thresholdCompensatedCurrentTime
        (m_TimeStamp_r.fGetCurrentTime().fGetDay(), 
            m_TimeStamp_r.fGetCurrentTime().fGetHour(), 
            m_TimeStamp_r.fGetCurrentTime().fGetMinute()+f_thresholdValue_r,
            m_TimeStamp_r.fGetCurrentTime().fGetSec());
        if (l_startTimeForDay >= l_thresholdCompensatedCurrentTime)
        {
            return true;
        }
        return false;
    }

    bool CMotionBusinnessLogic::fIsAfterEndTime(const float& f_thresholdValue_r)
    {
        auto l_endTimeForDay(m_motionDetectParam_r.fGetEndOfMonitoring().fGetCurrentDaySetup(m_TimeStamp_r));
        DailyDateTime l_thresholdCompensatedCurrentTime
        (m_TimeStamp_r.fGetCurrentTime().fGetDay(),
            m_TimeStamp_r.fGetCurrentTime().fGetHour(),
            m_TimeStamp_r.fGetCurrentTime().fGetMinute() + f_thresholdValue_r,
            m_TimeStamp_r.fGetCurrentTime().fGetSec());
        if (l_endTimeForDay <= l_thresholdCompensatedCurrentTime)
        {
            return true;
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