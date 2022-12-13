#include <stdio.h>

void pointer1(){
    printf("\nPointer1\n");
    int var = 5;
    printf("Var: %d\n",var);
    //var değişkeninden önce & işareti kullanılarak değişkenin bellekteki adresini alıyoruz
    printf("Adress of var: %d", &var);
    printf("\n");
}

void pointer2(){
    printf("\nPointer2\n");
    int var = 5;
    //adress değişkeni tanımlanırken * işareti kullanılması gerekir
    int* adress = &var;
    printf("Adress: %d\n",adress);
    //adress değişkeninden önce * işareti kullanılarak bellekteki adresten değişken değerini alıyoruz
    printf("Var of adress: %d", *adress);
    printf("\n");
}

void pointer3(){
    printf("\nPointer3\n");
    // var değişkeni tanımlandı
    int var = 5;
    // var bellekteki adresi adress değişkeninin adresine atandı
    int* adress = &var;
    // adress değişkeninin bellekteki adresinden değişken alındı ve değeri değiştirildi
    *adress = 10;
    // bellekteki adresten değer değiştiği için başta tanımlanan var değişkeninin değeride değişmiş oldu
    printf("Var: %d\n",var);
}

void pointer4(){
    printf("\nPointer4\n");
    //x array tanımlandı
    int x[4];
    //x array uzunluğu alındı
    int size = sizeof(x)/sizeof(x[0]);
    //x array kadar döngü başlatıldı
    for(int i = 0;i<size;i++){
        //arrayin her bir elemanının bellekteki adresi alındı
        printf("&x[%d] = %p\n", i, &x[i]);
    }
    //arrayin kendi adresi alındı(adresler hex olarak tutuluyor)
    printf("Address of array x: %p\n", x);
}

void pointer5(){
    printf("\nPointer5\n");
    //5 elemanlı x array tanımlandı
    int x[5] = {1, 2, 3, 4, 5};
    //ptr değişkeninin bellekteki adresine x arrayinin sıfırncı elemanın adresi atandı
    int* ptr = &x[0];
    for (int i = 0; i < sizeof(x)/sizeof(x[0]); i++)
    {
        //arrayler bellekte sıralı şekilde tutulur
        //bu şekilde bellek manipule edilebilir ancak &ptr+i anlaşılmadı !!!
        printf("*ptr+i:%d &x[i]:%d &ptr+i:%d \n",*ptr+i,&x[i],&ptr+i);
    }
}

void swap(int* n1, int* n2){
    //2 tane değişken bellekteki adresi istendi
    //yeni bir değişken oluşturup birinci adres değeri bir değişkene atandı
    int n = *n1;
    //ikinci değişken adresi birinci değişken adresine atandı
    //değerleri değiştirmek yerine sadece adres değiştirildi
    //bu örnek bu işlem için gereksiz olabilir ancak fonksiyonun birden fazla dönüş değeri olsun isteniyorsa kullanılır
    *n1 = *n2;
    //yeni değişken değeri ikinci değişkenin adresine atandı
    *n2 = n;
}

void pointer6(){
    printf("\nPointer6\n");
    //2 adet değişken tanımlandı
    int num1 = 5;
    int num2 = 10;
    //değişkenin swap fonksiyonundan önceki hali yazdırıldı
    printf("Before swap num1:%d num2:%d\n",num1,num2);
    //değişkenler swap fonksiyonuna gönderildi
    swap(&num1, &num2);
    //swap fonksiyonundan sonraki değişkenlerin hali yazdırıldı
    printf("After swap num1:%d num2:%d\n",num1,num2);
}

int main(){
    pointer1();
    pointer2();
    pointer3();
    pointer4();
    pointer5();
    pointer6();
    return 0;
}