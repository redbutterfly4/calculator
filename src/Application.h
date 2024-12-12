#ifndef APPLICATION_H
#define APPLICATION_H

class Application
{
public:
    static int main();

    Application() = delete;

private:
    static void setUpLoggerWithRotatingFiles();
};

#endif // APPLICATION_H
