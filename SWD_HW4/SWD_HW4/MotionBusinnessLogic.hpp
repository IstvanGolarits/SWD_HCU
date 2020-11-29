/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: Deciding if a warning shall be requested based on sensor input, time, and user-defined setups
/// --------------------------------------------------------

#ifndef MOTION_BUSINNESS_LOGIC_HPP
#define MOTION_BUSINNESS_LOGIC_HPP

#define DEFAULT_CONFIDENCE_IN_MOVEMENT_NEEDED  80
#define DEFAULT_MOVEMENT_SIZE_NEEDED 0.6f

#include "MotionCommInfo.hpp"
#include "MotionDetectionParams.hpp"
#include "Motion2SysInfo.hpp"

namespace istvan_richard
{
    class CMotionBusinnessLogic
    {
    public:
        //Param C'tor
        CMotionBusinnessLogic(CMotionCommInfo &f_motionCommInfo_r, CMotionDetectionParam &f_motionDetectParam_r,
            TimeStamp& f_timeStamp_r, CMotion2SysInfo& f_MotionToSysInfo_r):
            m_motionCommInfo_r(f_motionCommInfo_r),
            m_motionDetectParam_r(f_motionDetectParam_r),
            m_TimeStamp_r(f_timeStamp_r),
            m_MotionToSysInfo_r(f_MotionToSysInfo_r)
        {}

        /// <summary>
        ///  Updates the state variable (m_MotionToSysInfo_r.m_StateOfMotion_e) based on sensor info, time and user-defined parameters
        /// </summary>
        void fUpdateMotionLogic();

    private:
        //functions

        /// <summary>
        /// Decides if current time is within user-set time-window, extended with user-defined threshold
        /// </summary>
        /// <param name="f_thresholdValue_r"></param>
        /// <returns>
        /// Returns true if current time is in between of Start+-Threshold and End-+Threshold, false otherwise
        /// </returns>
        bool fIsInValidTime(const float& f_thresholdValue_r);
        /// <summary>
        /// Decides if current time is a later date, than user-set end-time +- user-set threshold
        /// </summary>
        /// <param name="f_thresholdValue_r"></param>
        /// <returns>
        /// Returns true, if current time is after the set end-time +- threshold
        /// </returns>
        bool fIsAfterEndTime(const float& f_thresholdValue_r);
        /// <summary>
        /// Decides if current time is a earlier date, than user-set start-time +- user-set threshold
        /// </summary>
        /// <param name="f_thresholdValue_r"></param>
        /// <returns>
        /// Returns true, if current time is before the set start-time +- threshold
        /// </returns>
        bool fIsBeforeStartTime(const float& f_thresholdValue_r);

        //referance variables
        CMotionCommInfo& m_motionCommInfo_r;
        CMotionDetectionParam& m_motionDetectParam_r;
        TimeStamp& m_TimeStamp_r;
        CMotion2SysInfo& m_MotionToSysInfo_r;
    };

}//end of namespace

#endif