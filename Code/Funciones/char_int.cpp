int char_int(char *p){
    int dec=dec_10(len_char(p)), num=0,len=len_char(p);
    for(int i=0; i<=len;i++){
        num=num+(p[i]-48)*dec;
        dec/=10;
    }
    return num;
}
int dec_10(int a){
    int dec=1;
    for(int i=1;i<a;i++){
        dec*=10;
    }
    return dec;
}
