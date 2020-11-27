/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file:
/// --------------------------------------------------------

#ifndef MOTION_2_SYS_INFO_HPP
#define MOTION_2_SYS_INFO_HPP

namespace istvan_richard
{
    class CMotion2SysInfo
    {
    public:
        enum class E_StateOfMotionBussiness
        {
            OFF =0,
            ALL_OK,
            SUS,
            WARNING_IN_TIME,
            WARNING_OUT_OG_TIME,
            ERROR
        };
        //C'Tor
        CMotion2SysInfo():
            m_StateOfMotion_e(E_StateOfMotionBussiness::ALL_OK)
        {}
        //Param C'Tor
        CMotion2SysInfo(const E_StateOfMotionBussiness& f_state_r):
            m_StateOfMotion_e(f_state_r)
        {}
        const E_StateOfMotionBussiness fGetMotionState() const
        {
            return this->m_StateOfMotion_e;
        }
        void fUpdateState(E_StateOfMotionBussiness f_newState_e)
        {
            m_StateOfMotion_e = f_newState_e;
        }
    private:
        E_StateOfMotionBussiness m_StateOfMotion_e;
    };

} //end of namespace

#endif

