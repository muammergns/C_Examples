#include <stdio.h>

//struct değişken gruplarını isimlendirmek için kullanılır
//örneğin bir ekranın en ve boy ölçülerini tutmak için birden fazla değişken oluşturulduğunda 
//yazması ve okuması zorlaşacaktır.
//bu şekilde bir tanımlama ile ayrı ayrı int değişken oluşturmaktansa bir defa screen değişkeni oluşturmak yeterli olacaktır
struct Screen
{
    int width;
    int height;
};

//iç içe struct yapılar mümkündür
struct Computer
{
    struct Screen screen;
    float cpu;
    int ram;
};

//typedef ile struct yapının gruplara ayrılması mümkündür
//örneğin aynı tip değişkenlere sahip birden fazla struct gerekiyorsa bu şekilde bir tanımlama ile gruplandırılabilir
//amaç sadece okuma ve yazmayı kolaylaştırmak
typedef struct Device
{
    int inputs;
    int outputs;
}devices1;


void struct1(){
    printf("\nStruct1\n");
    //screen1 adında yeni bir Screen objesi oluşturuldu
    struct Screen screen1;
    //screen1 oluşturulması ile 2 adet int değişken oluşturulmuş oldu karmaşa ortadan kalktı
    screen1.width = 1920;
    screen1.height = 1080;
    printf("Width:%d Height:%d\n",screen1.width,screen1.height);
}

void struct2(){
    printf("\nStruct2\n");
    //computer1 adında yeni bir Computer objesi oluşturuldu
    struct Computer computer1;
    //Computer yapısında ayrıca Screen yapısı tutuluyor
    //yani bu şekilde gruplandırma ile takip kolaylaştı
    computer1.screen.width = 640;
    computer1.screen.height = 480;
    computer1.cpu = 3.5f;
    computer1.ram = 4096;
    printf("CPU:%.2f GHz RAM:%d GB\n",computer1.cpu,computer1.ram);
    printf("Width:%d Px Height:%d Px\n",computer1.screen.width,computer1.screen.height);
}

void struct3(){
    printf("\nStruct3\n");
    //typedef ile devices1 adında yeni bir grup oluşturuldu
    //devices1 artık Device yapısına benzer ayrı bir yapı haline geldi
    //aynı zamanda burada yeni bir Device grubu oluşturuldu
    typedef struct Device devices2;
    //ve bu yapının nesneleri devices1 ve devices2 ye bağlandı
    //aslında aynı struct yapının elemanları ancak kod okuma anlamında çok yaralı
    //fatek, devices2 değildir. aynı şekilde beijer, device1 değildir
    devices1 fatek,xinje;
    devices2 beijer,beckhoff;
    fatek.inputs = 36;
    fatek.outputs = 24;
    beijer.inputs = 8;
    beijer.outputs = 16;
    printf("Fatek inputs:%d outputs:%d\n",fatek.inputs,fatek.outputs);
    printf("Beijer inputs:%d outputs:%d\n",beijer.inputs,beijer.outputs);
}

void struct4(){
    printf("\nStruct4\n");
    //struct işaretçi olarak kullanılması
    //işaretçi olarak screen1 oluşturuldu
    struct Screen* screen1;
    //değişken olarak screen2 oluşturuldu
    struct Screen screen2;
    //screen2 değerleri atandı
    screen2.width = 1920;
    screen2.height = 1080;
    //screen2 bellekteki adresi screen1 aktarıldı
    screen1 = &screen2;
    //screen1 değişkenlerine ulaşmak için -> kullanılır
    printf("Screen width:%d height:%d\n",screen1->width,screen1->height);
}

void displayStruct5(struct Screen s){
    //parametre olarak struct alınabilir
    printf("displayStruct5 Width:%d Height:%d\n",s.width,s.height);
}

struct Screen getScreen(){
    struct Screen screen1;
    screen1.width = 1920;
    screen1.height = 1080;
    //dönüş değeri olarak struct gönderilebilir
    return screen1;
}

void struct5(){
    printf("\nStruct5\n");
    struct Screen screen1;
    screen1.width = 1920;
    screen1.height = 1080;
    //struct fonksiyolara parametre olarak gönderilebilir.
    displayStruct5(screen1);
    struct Screen screen2;
    //struct fonksiyondan dönüş değeri olarak alınabilir
    screen2 = getScreen();
    printf("getScreen Width:%d Height:%d\n",screen2.width,screen2.height);
}

void addDevicesInputsAndOutputs(struct Device d1, struct Device d2, devices1* result){
    result->inputs = d1.inputs + d2.inputs;
    result->outputs = d1.outputs + d2.outputs;
}

void struct6(){
    printf("\nStruct6\n");
    typedef struct Device devices2;
    devices2 fatek,beijer,result;
    // yukarısı direk olarak devices1 fatek,beijer,result; şeklinde oluşturulabilirdi
    fatek.inputs = 36;
    fatek.outputs = 24;
    beijer.inputs = 8;
    beijer.outputs = 16;
    //fonksiyonu çağırırken veri tipinin ne oladuğuna bakılmaksızın temel struct yapıyı dikkate alıyor.
    addDevicesInputsAndOutputs(fatek,beijer,&result);
    printf("addDevicesInputsAndOutputs inputs:%d outputs:%d\n",result.inputs,result.outputs);
}

int main(){
    struct1();
    struct2();
    struct3();
    struct4();
    struct5();
    struct6();
    return 0;
}
