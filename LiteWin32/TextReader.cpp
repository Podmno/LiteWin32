#include "TextReader.h"


TextReader::TextReader(){

    head = new words;
    head->next = NULL;

    list_head = new wordslist;
    list_head->next = NULL;
    list_head->number = 0;


}

TextReader::TextReader(LPWSTR data)
{

    location = data;


    head = new words;
    head->next = NULL;

    list_head = new wordslist;
    list_head->next = NULL;
    list_head->number = 0;


}

void TextReader::start(){

    read_function();

    read_all();

    print_function();

    print_all();


}

void TextReader::read_function(){

    

    if (!location) {

        file = new std::ifstream(location);
    }
    else {

        file = new std::ifstream("article.txt");

    }

    if(!file){

        std::cout << "[EngFlex] Open Error!" << std::endl;
        return;

    }

    char c;

    char tempdata[100];
    int current = 0;

    words* cur = head;
    

    while((c=file->get())!=EOF){
        
        if(c>=65 && c<=90){
            c= c+32;
        }

        if((c>=97 && c<=122)||(c==39)){
            
            tempdata[current] = c;
            current++;

        } else {

            
            cur->length = current ;
            for(int i=0;i<=current;i++){
                cur->letter[i] = tempdata[i];
            }
            cur->next = new words;
            cur = cur->next;
            cur->next = NULL;

            current = 0;
            


        }

        
    }

    file->close();



}

void TextReader::read_all(){

    words* temp = head;
    words* next = head->next;

    int wordindex = 0;

    while(temp!=NULL){

        next = temp->next;
        
        std::cout << "Word "<<wordindex+1<<": ";

        for(int i=0;i<temp->length;i++){

            std::cout << temp->letter[i];

        }

        wordindex++;

        std::cout << std::endl ;        

        temp = next;

    }



}

void TextReader::print_function(){

    words* cur = head;
    wordslist* list_cur = list_head;
    
    wordslist* list_temp = nullptr;

    while(cur!=NULL){
    
        while(list_cur!=NULL){
            
            if(list_cur->length == cur->length){

                for(int i=0;i<cur->length;i++){

                    if(list_cur->letter[i]!=cur->letter[i]){
                        goto again;
                    }

                }

                list_cur->number++;
                goto outrange;


            }

            again:

            list_temp = list_cur;

            list_cur = list_cur->next;

        }

        list_temp->next = new wordslist;
        list_temp = list_temp->next;
        list_cur = list_temp;

        for(int m=0;m<cur->length;m++){

            list_cur->letter[m] = cur->letter[m];

        }

        list_cur->length = cur->length;
        list_cur->number = 1;
        list_cur->next = NULL;

        outrange:

        cur = cur->next;
        list_cur = list_head;


    }

}

void TextReader::print_all(){

    wordslist* cur = list_head->next;

    std::cout<<std::endl;

    while(cur!=NULL){

        std::cout << "Word ";

        for(int i=0;i<cur->length;i++){

            std::cout << cur->letter[i];

        }

        std::cout<<": ";

        std::cout<<cur->number<<" times."<<std::endl;

        cur = cur->next;


    }





}

TextReader::~TextReader(){

    words* temp = head;
    words* next = head->next;

    while(temp!=NULL){

        next = temp->next;
        delete temp;
        temp = next;

    }



}
