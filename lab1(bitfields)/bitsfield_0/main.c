//найти и вывести целое число в 4 раза меньше заданного, не выполняя деления и не используя операцию взятия остатка от деления
#include <stdio.h>

struct mask{
    unsigned int i0:1, i1:1, i2:1, i3:1, i4:1, i5:1, i6:1, i7:1, i8:1,
    i9:1, i10:1, i11:2, i12:1, i13:1, i14:1, i15:1, i16:1, i17:1, i18:1, i19:1, i20:1, i21:1, i22:1, i23:1, i24:1,
            i25:1, i26:1, i27:1, i28:1, i29:1, i30:1, i31:1;
};

int main() {
    int num;
    scanf("%d",&num);
    struct mask *p= (struct mask*) &num;
    printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",
           p->i31,p->i30,p->i29,p->i28,p->i27,p->i26,p->i25,p->i24,p->i23,p->i22,p->i21,p->i20,p->i19,p->i18,p->i17, p->i16,
           p->i15,p->i14,p->i13,p->i12,p->i11,p->i10,p->i9,p->i8,p->i7,p->i6,p->i5,p->i4,p->i3,p->i2,p->i1, p->i0);
    p->i0=p->i2,p->i1=p->i3, p->i2=p->i4, p->i3=p->i5, p->i4=p->i6, p->i5=p->i7, p->i6=p->i8, p->i7=p->i9,
    p->i8=p->i10, p->i9=p->i11, p->i10=p->i12,p->i11=p->i13, p->i12=p->i14, p->i13=p->i15, p->i14=p->i16,
            p->i15=p->i17, p->i16=p->i18, p->i17=p->i19, p->i18=p->i20, p->i19=p->i21, p->i20=p->i22, p->i21=p->i23, p->i22=p->i24,
            p->i23=p->i25, p->i24=p->i26, p->i25=p->i27,p->i26=p->i28, p->i27=p->i29, p->i28=p->i30, p->i29=p->i31;
    printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",p->i29,p->i28,p->i27,p->i26,p->i25,p->i24,p->i23,p->i22,p->i21,p->i20,p->i19,p->i18,p->i17, p->i16,
           p->i15,p->i14,p->i13,p->i12,p->i11,p->i10,p->i9,p->i8,p->i7,p->i6,p->i5,p->i4,p->i3,p->i2,p->i1, p->i0);
    return 0;
}
