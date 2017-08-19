class TextEdit;
class editorBase
{
    TextEdit *editor;
public:
    editorBase(){editor=0;}
    void setEditor(TextEdit *);
    TextEdit * editorInfo();
    virtual void createConnection();
    virtual ~editorBase();
};