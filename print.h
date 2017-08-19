class editorBase;
class printText:public editorBase
{
        QPrinter *printer;
    public:
        printText();
        void createConnection();

}