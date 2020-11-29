/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------




#ifndef OUTPUT_INFO_CONFIG_HPP
#define OUTPUT_INFO_CONFIG_HPP

#include <stdlib.h>
#include <string>
#include <vector>

namespace istvan_richard
{
    class COutputInfoConfig
    {
    public:
        enum class E_ComType
        {

        };

        struct Contact
        {
            std::string m_Address_s;
            std::string m_Name_s;
            int m_PriorityOfContact_i64;
        };

        const Contact fGetPrimaryContact() const;
        const  std::vector<Contact> fGetNonPrimaryContactList() const;

    private:
        Contact m_PrimaryContact_s;
        std::vector<Contact>  m_NonPrimaryContactList_as;
        
    };


}//end of namespace

#endif
