/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef MOTION_COMM_INFO_HPP
#define MOTION_COMM_INFO_HPP

#define DEFAULT_MOTION_MOVEMENT_SIZE 0
#define DEFAULT_MOTION_CONFIDENCE 0
#define DEFAULT_DETECTED_STATE 0!=0

namespace istvan_richard
{
    class CMotionCommInfo
    {
    public:
        //C'Tor'
        CMotionCommInfo() :
            m_MovementSize_f64(DEFAULT_MOTION_MOVEMENT_SIZE),
            m_ConfidenceInMovement_i32(DEFAULT_MOTION_CONFIDENCE),
            m_MovementDetected_b(DEFAULT_DETECTED_STATE)
        {}
        //Copy C'Tor
        CMotionCommInfo(const CMotionCommInfo& f__r):
            m_MovementSize_f64(0),
            m_ConfidenceInMovement_i32(0),
            m_MovementDetected_b(DEFAULT_DETECTED_STATE)
        {
            if (this != &f__r)
            {
                this->m_MovementSize_f64 = f__r.m_MovementSize_f64;
                this->m_ConfidenceInMovement_i32 = f__r.m_ConfidenceInMovement_i32;
                this->m_MovementDetected_b = f__r.m_MovementDetected_b;
            }
        }
        //Parametrised C'Tor
        CMotionCommInfo(const float& f_moveSize_r, const int& f_confidentInMove_r, const bool& f_movedetct_r) :
            m_MovementSize_f64(f_moveSize_r),
            m_ConfidenceInMovement_i32(f_confidentInMove_r),
            m_MovementDetected_b(f_movedetct_r)
        {}

        const float fGetMovementSize() const
        {
            return m_MovementSize_f64;
        }
        const int fGetConfidenceInMovement() const
        {
            return m_ConfidenceInMovement_i32;
        }
        const bool fGetMovementDetected() const
        {
            return m_MovementDetected_b;
        }

    private:
        float m_MovementSize_f64;
        int m_ConfidenceInMovement_i32;
        bool m_MovementDetected_b;

    };

}//end of namespace

#endif
