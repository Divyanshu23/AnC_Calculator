#include <iostream>
#include <algorithm>

bool iequals(const std::string& a, const std::string& b);

int main() {
    //variable to store the number of semesters student has registered to far
    short N;
    // variables to store credits in last semester and total credits so far respectively
    int SC,TC;

    //Introductory message and taking inputs from user
    std::cout<<"Greetings"<<std::endl<<"Welcome to the AP/WARNING calculator"
    <<" brought to you by Academics and Career Council, IIT KANPUR."<<std::endl;
    while(1) {
        std::cout<<"Please enter the number of semesters you have registered for so far!"<<std::endl;
        std::cin>>N;
        // std::cout<<std::endl;
        if(N<0 || N>8) {
            std::cout<<"Please enter your value within the bounds 0 and 8";
            std::cout<<std::endl;
            continue;
        }
        std::cout<<"Please enter the number of credits completed in the last regular semester"<<std::endl;
        std::cin>>SC;
        // std::cout<<std::endl;
        std::cout<<"Please enter the total number of credits completed till this point of time"<<std::endl;
        std::cin>>TC;
        // std::cout<<std::endl;
        break;
    }
    bool flag1=false;
    bool flag2=false;
    //check conditions for Warning

    if((SC>=30 && ((N*(24+N))<=TC && TC<(36*N))) || SC<30 && TC>=(36*N)) {
        std::cout<<"You are on Warning"<<std::endl<<"Thanks for using our calculator. "
        <<"All the best for your future endeavours"<<std::endl;
        return 0;
    }

    //check conditions for AP

    if((SC>=30 && (TC<(N*(24+N)))) || (SC<30 && ((N*(24+N))<= TC && TC<(36*N)))) {
        std::cout<<"You are on Academic Probabation"<<std::endl<<"THanks for using our calculator. "
        <<"All the best for your future endeavours"<<std::endl;
        return 0;
    }
    std::string ap_in_last,default_value;
    std::cout<<"Were you on Academic Probabation in previous semester? Please write Yes or No!";
    std::cout<<std::endl;
    std::cin>>ap_in_last;
    // std::cout<<std::endl;
    default_value = "Yes";
    flag2 = iequals(ap_in_last,default_value);
    if(!flag2 && (SC<30 && TC<(N*(24+N)))) {
        flag1 = true;
        std::cout<<"You are on Academic Probabation"<<std::endl<<"THanks for using our calculator. "
        <<"All the best for your future endeavours"<<std::endl;
        return 0;
    }

    //check condition for program termination
    if(flag1 && (SC<30 && TC<(N*(24+N)))) {
        std::cout<<"Your UG Program is on the verge of termination. You can appeal to the Chairperson,"
        <<" Academic Senate providing your valid reasons"<<std::endl
        <<"THanks for using our calculator. "<<"All the best for your future endeavours"<<std::endl;
        return 0;
    }
    std::cout<<"All fine. You are doing good. Cheers!"<<std::endl;
    return 0;
}

bool iequals(const std::string& a, const std::string& b)
{
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}