bool compare(char a[], char b[]){
    int t1 = len_char(a);
    int t2 = len_char(b);
    if(t1 == t2){ //Hace falta verificar tamaño
        for(int i =0; i<t1; i++){
            if((a[i]) != (b[i])){ //Si el caracter correspondiente es
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}
