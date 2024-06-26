int canConstruct(char * ransomNote, char * magazine){
    int i = 0;
    int alphs[27] = {0};
    
    for (int i = 0; magazine[i]; i++){
        alphs[magazine[i] - 'a']++;
    }

    while (ransomNote[i]){
        if (alphs[ransomNote[i] - 'a'])
            alphs[ransomNote[i] - 'a']--;
        else
            return 0;
        i++;
    }

    return 1;
}
