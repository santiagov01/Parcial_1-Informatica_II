int char_int(char *p){
    int dec=dec_10(len_char(p)), num=0,len=len_char(p);
    for(int i=0; i<=len;i++){
        num=num+(p[i]-48)*dec;
        dec/=10;
    }
    return num;
}
