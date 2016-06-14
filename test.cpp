#include <iostream>
#include <string>

class Test
{
public:
    /*Test(string _sth) {
        something = _sth;
    }*/
    void setSomething(std::string sth)
    {
        something = sth;
    }

    std::string getSomething()
    {
        return something;
    }
private:
    std::string something;
};

class superTest: public Test
{
    //Inheritance class is just a class (in some point).
};

class ultimateTest: public Test//, public superTest
{
public:
    void beatAThing()
    {
        std::cout<< "Beat everything" << std::endl;
    }
};

int main(int argc, char** argv)
{
    //test class with #public and #private
    /*Test t("sth.");
    cout<< "t.getSomething(): " << t.getSomething() << endl;*/

    //superTest sp;
    //sp.setSomething("a");
    //cout<< "sp.getSomething(): " << sp.getSomething() << endl;

    ultimateTest ut;
    ut.setSomething(std::string("utl"));
    ut.beatAThing();
    std::cout << ut.getSomething() << std::endl;
    return 0;
}
