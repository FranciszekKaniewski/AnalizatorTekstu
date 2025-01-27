class App{
public:
    static bool isRunning;

    void init();
    void handleEvents();
    bool running() {return isRunning;};
    void clean();
};