#include <stdio.h>
#include <math.h>

int main(void) {
  float BMI,a,b;
  int c;
  c=1;
  while (c==1){
    printf("請輸入你的體重:");
    scanf("%f",&a);
    printf("請輸入你的身高:");
    scanf("%f",&b);
    b=b/100.0;
    BMI=a/(b*b);
    printf("你的BMI:%f\n",BMI);
    if (BMI>=35){
      printf("你的BMI是%f屬於重度肥胖\n",BMI);
    }
    else if (BMI>=30 && BMI<35){
      printf("你的BMI是%f屬於中度肥胖\n",BMI);
    }
    else if (BMI>=27 && BMI<30){
      printf("你的BMI是%f屬於輕度肥胖\n",BMI);
    }
    else if (BMI>=24 && BMI<27){
      printf("你的BMI是%f屬於過重\n",BMI);
    }
    else if (BMI>=18.5 && BMI<24){
      printf("你的BMI是%f屬於康體位\n",BMI);
    }
    else if (BMI<18.5){
      printf("你的BMI是%f屬於過輕\n",BMI);
    }
    printf("再次使用請輸入1不使用輸入0");
    scanf("%d",c);
    if(c==0){
      break;
    }
  }
  return 0;
}