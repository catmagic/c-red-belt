#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;

bool operator<(const Date& lhs,const Date& rhs)
{
    return make_tuple(lhs.year,lhs.month,lhs.day)<make_tuple(rhs.year,rhs.month,rhs.day);
}
bool operator==(const Date& lhs,const Date& rhs)
{
    return make_tuple(lhs.year,lhs.month,lhs.day)==make_tuple(rhs.year,rhs.month,rhs.day);
}
ostream& operator<<(ostream& out,const Date& date)
{
    return out<<date.year<<" "<<date.month<<" "<<date.day<<" ";
}
bool operator<(const Time& lhs,const Time& rhs)
{
    return make_tuple(lhs.hours,lhs.minutes)<make_tuple(rhs.hours,rhs.minutes);
}
bool operator==(const Time& lhs,const Time& rhs)
{
    return make_tuple(lhs.hours,lhs.minutes)==make_tuple(rhs.hours,rhs.minutes);
}
ostream& operator<<(ostream& out,const Time& time)
{
    return out<<time.hours<<" "<<time.minutes<<" ";
}
void pr( Date& lhs,const Date& rhs)
{
    lhs.year=rhs.year;
    lhs.month=rhs.month;
    lhs.day=rhs.day;

}
void pr( Date& lhs,const string& rhs)
{
    stringstream ss;
    ss<<rhs;char tmp;
    ss>>lhs.year>>tmp>>lhs.month>>tmp>>lhs.day;

}
void pr( Time& lhs,const Time& rhs)
{
    lhs.hours=rhs.hours;
    lhs.minutes=rhs.minutes;

}
void pr( Time& lhs,const string&  rhs)
{
     stringstream ss;
    ss<<rhs;char tmp;
    ss>>lhs.hours>>tmp>>lhs.minutes;

}
void pr(int &p1,int p2)
{
    p1=p2;
}
void pr(int &p1,const string& p2)
{
    p1=stoi(p2);
}
void pr(string &p1,const string p2)
{
    p1=p2;
    __LINE__;
}

#define UPDATE_FIELD(ticket, field, values)  {\
map<string, string>::const_iterator it;\
 it= values.find(#field);\
  if (it != values.end()) {\
    pr(ticket.field , it->second);}\
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}