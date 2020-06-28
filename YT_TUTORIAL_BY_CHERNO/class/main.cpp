#include <iostream>


//example for class or structure level static keyword
class Entity{
public:
    static int x,y;

    static void print(){
        std::cout << "values: " << x << " "<< y << std::endl; 
    }
};

//example of how class could be created
class Log{
public:
    enum logLevel{
        traceLogLevel=0,debugLogLevel,infoLogLevel,warnLogLevel,errorLogLevel
    };
    
private:
    logLevel m_LogLevel;
public:

    Log() = delete // to delete default constructor 

    Log(){

    }

    Log(logLevel level){
        this->m_LogLevel = level;
    }

    void setLogLevel(logLevel level){
        m_LogLevel = level;
    }

    void warn(const char* message){
        if(m_LogLevel <= warnLogLevel)
            std::cout << "[warning]: " << message << std::endl;
    }

    void error(const char* message){
        if(m_LogLevel <= errorLogLevel)
            std::cout << "[error]: " << message << std::endl;
    }

    void debug(const char* message){
        if(m_LogLevel <= debugLogLevel)
            std::cout << "[debug]: " << message << std::endl;
    }

    void info(const char* message){
        if(m_LogLevel <= infoLogLevel)
            std::cout << "[info]: " << message << std::endl;
    }

    void trace(const char* message){
        if(m_LogLevel <= traceLogLevel)
            std::cout << "[trace]: " << message << std::endl;
    }
};

//basic structure of class
class Sample{
public:
    int x,y;
    void print(){
        std::cout << "class field values are "<< x << " and " << y << std::endl;
    }
};

//class and struct are mainly same 
//struct and class both can have data and methods as member of it.
//In structure, all members are public by default.
//In class, all members are private by default.

//static keyword to class member make them shared across the all instances of that class. 

int Entity::x;
int Entity::y;

int main(){
    Sample sample;
    sample.x = 5;
    sample.y = 10;
    sample.print();

    Log log(Log::warnLogLevel);
    log.warn("Hello");
    log.error("Hello");
    log.info("Hello");
    log.debug("Hello");
    log.trace("Hello");


    Entity e1;
    Entity e2;

    Entity::x = 5;
    Entity::y = 10;

    Entity::print();
    
    
}