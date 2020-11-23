/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: containing interfaces, and system setup handlers.
/// --------------------------------------------------------

#ifndef INPUT_UI_WEB_HPP
#define INPUT_UI_WEB_HPP

namespace istvan_richard
{
    class CInputUIWeb
    {
    public:
        const bool fWasAnyRequest() const;

    private:
        bool m_UnhandledUserRequest_b;

    };


}//end of namespace



#endif

