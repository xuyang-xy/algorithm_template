int rand10() {
    while(true){
        int rand49 = (rand7() - 1) * 7 + rand7();
        if (rand49 <= 40)
            return ((rand49 % 10) + 1);
    }
}