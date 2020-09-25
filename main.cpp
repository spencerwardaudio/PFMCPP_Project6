/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    T(int v, const char* c) :  //1
    value(v),//2
    title(c) //3
    {

    }
    int value;
    std::string title;
};

struct ComparisonCalc                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float pop { 3.1f }, shift { 1.0f };
    float moving(float& updateVal)      //12
    {
        std::cout << "U's pop value: " << this->pop << std::endl;
        this->pop = updateVal;
        std::cout << "U's pop updated value: " << this->pop << std::endl;

        while( std::abs(this->pop - this->shift) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            this->pop -= 1.0f;
        }
        
        std::cout << "U's shift updated value: " << this->shift << std::endl;
        return this->shift * this->pop;
    }
};

struct B
{
    static float turn(U& that, float& updateVal )        //10
    {
        std::cout << "U's pop value: " << that.pop << std::endl;
        that.pop = updateVal;
        std::cout << "U's pop updated value: " << that.pop << std::endl;

        while( std::abs(that.pop - that.shift) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            that.shift += ((that.pop) - (that.shift)) / 3 ;
        }

        std::cout << "U's shift updated value: " << that.shift << std::endl;
        return that.shift * that.pop;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T bitPop(3, "y");                                             //6
    T bitShift(2, "e");                                             //6

    ComparisonCalc f;                                            //7
    auto* smaller = f.compare( bitPop, bitShift);                              //8

    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->title << std::endl; //9
    }
    else 
    {
        std::cout << bitPop.title << " and " << bitShift.title << " are equivalent << " << std::endl; //9
    }

    U name3;
    float updatedValue = 5.f;
    std::cout << "[static func] name3's multiplied values: " << B::turn(name3, updatedValue) << std::endl;                  //11

    U name4;
    std::cout << "[member func] name4's multiplied values: " << name4.moving( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
