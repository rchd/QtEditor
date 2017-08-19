#include"base.h"
void editorBase::setEditor(TextEdit *editor)
{
    this->editor=editor;
}
void editorBase::createConnection()
{
    
}
TextEdit * editorBase::editorInfo()
{
    return editor;
}
editorBase::~editorBase()
{

}