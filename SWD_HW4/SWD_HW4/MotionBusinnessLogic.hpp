/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef MOTION_BUSINNESS_LOGIC_HPP
#define MOTION_BUSINNESS_LOGIC_HPP

#include "MotionCommInfo.hpp"
#include "MotionDetectionParams.hpp"
#include "Motion2SysInfo.hpp"

namespace istvan_richard
{
    class CMotionBusinnessLogic
    {
    public:
        CMotionBusinnessLogic(CMotionCommInfo &f_motionCommInfo_r, CMotionDetectionParam &f_motionDetectParam_r,
            TimeStamp& f_timeStamp_r, CMotion2SysInfo& f_MotionToSysInfo_r):
            m_motionCommInfo_r(f_motionCommInfo_r),
            m_motionDetectParam_r(f_motionDetectParam_r),
            m_TimeStamp_r(f_timeStamp_r),
            m_MotionToSysInfo_r(f_MotionToSysInfo_r),
            m_StartOfMovement(),
            m_WasAlreadyMoveDetect_b(false)
        {}

        void fUpdateMotionLogic();

    private:
        //functions
        int fGetTimeDiffInSec();
        int fTimeInSecBetweenTwoDates(DailyDateTime& f_RefStamp_r, DailyDateTime& f_currentStamp_r);
        bool fIsInValidTime(const float& f_thresholdValue_r);
        bool fIsAfterEndTime(const float& f_thresholdValue_r);
        bool fIsBeforeStartTime(const float& f_thresholdValue_r);
        void fCheckForMotion();
        void fSetWarningState();

        //variables
        CMotionCommInfo& m_motionCommInfo_r;
        CMotionDetectionParam& m_motionDetectParam_r;
        TimeStamp& m_TimeStamp_r;
        CMotion2SysInfo& m_MotionToSysInfo_r;

        DailyDateTime m_StartOfMovement;
        bool m_WasAlreadyMoveDetect_b;
    };

}//end of namespace

#endif