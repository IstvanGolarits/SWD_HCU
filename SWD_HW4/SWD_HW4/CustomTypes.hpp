/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: Contains all custom made types
/// --------------------------------------------------------

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

namespace istvan_richard
{
    class DailyDateTime
    {
    public:
        //Default C'Tor
        DailyDateTime() :
            m_Day_s(" "),
            m_NumOfDay_i32(0),
            m_Hour_i32(0),
            m_Minutes_i32(0),
            m_Seconds_i32(0)
        {}
        //Setter, param C'Tor
        DailyDateTime(std::string f_day_s, int f_hour_i32, int f_minutes_i32, int f_seconds_i32) :
            m_Day_s(f_day_s),
            m_NumOfDay_i32(0),
            m_Hour_i32(f_hour_i32),
            m_Minutes_i32(f_minutes_i32),
            m_Seconds_i32(f_seconds_i32)
        {
            if ("MONDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 1;
            }
            else if ("TUESDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 2;
            }
            else if ("WEDNESDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 3;
            }
            else if ("THURSDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 4;
            }
            else if ("FRYDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 5;
            }
            else if ("SATURDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 6;
            }
            else if ("SUNDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 7;
            }
            else
            {
                m_NumOfDay_i32 = 0;
                std::printf("Error Occured, Wrong Name for Day");
            }
        }
        //Copy C'tor
        DailyDateTime(const DailyDateTime& f__r)
        {
            if (this != &f__r)
            {
                this->m_Day_s = f__r.m_Day_s;
                this->m_Hour_i32 = f__r.m_Hour_i32;
                this->m_Minutes_i32 = f__r.m_Minutes_i32;
                this->m_Seconds_i32 = f__r.m_Seconds_i32;
                this->m_NumOfDay_i32 = f__r.m_NumOfDay_i32;
            }
        }

        const std::string fGetDay() const
        {
            return this->m_Day_s;
        }
        const int fGetNumOfDay() const
        {
            return this->m_NumOfDay_i32;
        }
        const int fGetHour() const
        {
            return this->m_Hour_i32;
        }
        const int fGetMinute() const
        {
            return this->m_Minutes_i32;
        }
        const int fGetSec() const
        {
            return this->m_Seconds_i32;
        }

    private:
        std::string m_Day_s;
        int m_NumOfDay_i32;
        int m_Hour_i32;
        int m_Minutes_i32;
        int m_Seconds_i32;
    };

    class TimeStamp
    {
    public:
        //C'Tor
       TimeStamp():
           m_CurrentTime(std::string("MONDAY"), 12, 0, 0)
       {}
       void fUpdateCurrentTime(const DailyDateTime& f_CurrTimeInfo_r)
       {
           m_CurrentTime = f_CurrTimeInfo_r;
       }
       DailyDateTime fGetCurrentTime()
       {
           return m_CurrentTime;
       }
    private:
        DailyDateTime m_CurrentTime;

    };

    class DateTime
    {
    public:
        //default C'tor
        DateTime():
            m_Days_adt()
        {}
        //Param C'tors
        DateTime(DailyDateTime &f_DateTime_r) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3,
            DailyDateTime& f_DateTime_r4) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
            m_Days_adt.push_back(f_DateTime_r4);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3,
            DailyDateTime& f_DateTime_r4, DailyDateTime& f_DateTime_r5) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
            m_Days_adt.push_back(f_DateTime_r4);
            m_Days_adt.push_back(f_DateTime_r5);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3,
            DailyDateTime& f_DateTime_r4, DailyDateTime& f_DateTime_r5, DailyDateTime& f_DateTime_r6) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
            m_Days_adt.push_back(f_DateTime_r4);
            m_Days_adt.push_back(f_DateTime_r5);
            m_Days_adt.push_back(f_DateTime_r6);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3,
            DailyDateTime& f_DateTime_r4, DailyDateTime& f_DateTime_r5, DailyDateTime& f_DateTime_r6,
            DailyDateTime& f_DateTime_r7) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
            m_Days_adt.push_back(f_DateTime_r4);
            m_Days_adt.push_back(f_DateTime_r5);
            m_Days_adt.push_back(f_DateTime_r6);
            m_Days_adt.push_back(f_DateTime_r7);
        }
        //Copy C'Tor
        DateTime(const DateTime& f__r)
        {
            if (this != &f__r)
            {
                for (auto l_it_p = &f__r.m_Days_adt.begin(); l_it_p!= &f__r.m_Days_adt.end(); ++l_it_p)
                {
                    DailyDateTime l_currentDate = **l_it_p;
                    this->m_Days_adt.push_back(l_currentDate);
                }
            }
        }
        const std::vector<DailyDateTime> fGetDaysVector() const
        {
            return m_Days_adt;
        }

        DailyDateTime fGetCurrentDaySetup(TimeStamp& f_TimeStamp_r)
        {
            const std::string l_currentDay_s = f_TimeStamp_r.fGetCurrentTime().fGetDay();
            for (auto l_it_p = this->m_Days_adt.begin();
                l_it_p != this->m_Days_adt.end();
                l_it_p++)
            {
                std::string l_refDay_s = l_it_p->fGetDay();
                if (l_refDay_s == l_currentDay_s)
                {
                    return *l_it_p;
                }
            }
            DailyDateTime l_ret(std::string(""), 0, 0, 0);
            return l_ret;
            std::printf("NoMatchingDaysInArray");
        }

        int fGetTimeInSecToRef_sameDay(TimeStamp l_currentTime)
        {
            auto l_refDay(fGetCurrentDaySetup(l_currentTime));
            int l_ret_i32(0);
            l_ret_i32 += 60 * 60 * (l_refDay.fGetHour() - l_currentTime.fGetCurrentTime().fGetHour());
            l_ret_i32 += 60 * (l_refDay.fGetMinute() - l_currentTime.fGetCurrentTime().fGetMinute());
            l_ret_i32 += (l_refDay.fGetSec() - l_currentTime.fGetCurrentTime().fGetSec());
            return l_ret_i32;
        }

        int fGetTimeInSecSinceRef_sameDay(TimeStamp l_currentTime)
        {
            auto l_refDay(fGetCurrentDaySetup(l_currentTime));
            int l_ret_i32(0);
            l_ret_i32 += 60 * 60 * (l_currentTime.fGetCurrentTime().fGetHour() - l_refDay.fGetHour());
            l_ret_i32 += 60 * (l_currentTime.fGetCurrentTime().fGetMinute() - l_refDay.fGetMinute() );
            l_ret_i32 += (l_currentTime.fGetCurrentTime().fGetSec() - l_refDay.fGetSec());
            return l_ret_i32;
        }

    private:
        std::vector<DailyDateTime> m_Days_adt;
    };

    
}//end of namespace

#endif