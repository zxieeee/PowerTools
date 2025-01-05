#include<iostream>
#include <vector>
#include "../header/core.h"
using namespace std;
                   
int main() 
{
   
    std::vector<std::string> files = 
    {
        //these files should exist write path here 
        "/workspaces/gtk_multimedia_organiser/folder/image1.png",
        "/workspaces/gtk_multimedia_organiser/folder/document1.txt",
        "/workspaces/gtk_multimedia_organiser/folder/notes.txt",
        "/workspaces/gtk_multimedia_organiser/folder/presentation.pptx"
    };

    save(files);
    return 0;
}