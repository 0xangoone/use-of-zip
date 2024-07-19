#include <zip.h>
#include <iostream>
#include <fstream>
#include <filesystem>
int main() {
    zip_t *zip = zip_open("out.zip", 0 , nullptr);

    /*const char *filename = "hello.txt";
    zip_source_t *source = zip_source_file(zip, filename, 0, 0);
    zip_file_add(zip,filename,source,ZIP_FL_OVERWRITE);
    */
    
    zip_file_t *file = zip_fopen(zip,"example.txt",0);
    char content[14];
    zip_fread(file,content,16);
    std::cout << content << std::endl;
    zip_fclose(file);
    zip_dir_add(zip,"hello",0);

    

    char data[] = "hihihihi\n";
    zip_source_t *source = zip_source_buffer(zip,data,sizeof(data),0);
    
    zip_file_add(zip,"hello/text.txt",source,0);


    zip_close(zip);


    return 0;
}
