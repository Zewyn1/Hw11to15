#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned char CheckBit(unsigned int uValue)
{
    unsigned char ucResult = 0;
    unsigned char ucMask = 1;
    unsigned char ucBit = 0;
    while (ucBit < 16)
    {
        if (uValue & ucMask)
        {
            ucResult++;
        }
        ucMask <<= 1;
        ucBit++;
    }
    if (ucResult == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void reverse(char* str) {
    int i, j;
    char c;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}
void VMirror(unsigned char *pImage)
{
    unsigned char ucRow = 0;
    unsigned char ucCol = 0;
    unsigned char ucTemp = 0;
    while (ucRow < 8)
    {
        ucCol = 0;
        while (ucCol < 4)
        {
            ucTemp = pImage[ucRow * 4 + ucCol];
            pImage[ucRow * 4 + ucCol] = pImage[ucRow * 4 + 3 - ucCol];
            pImage[ucRow * 4 + 3 - ucCol] = ucTemp;
            ucCol++;
        }
        ucRow++;
    }
}
void Conv(int sValue, char *pBuffer)
{
    if (sValue < 0)
    {
        sprintf(pBuffer, "%d", sValue);
    }
    else
    {
        sprintf(pBuffer, " %d", sValue);
    }
}
void push(int *arr, int val)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = val;
            break;
        }
    }
}
int pop(int *arr)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = 0;
            return temp;
        }
    }
    return 0;
}
void print_array(int *arr)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void print_array_char(char *arr)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}
//check if function is empty
int isEmpty(int *arr)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (arr[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
//check if function is full
int isFull(int *arr)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (arr[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}
//function to check if the value is in the array
int isInArray(int *arr, int val)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (arr[i] == val)
        {
            return 1;
        }
    }
    return 0;
}
void bubbleSort(int *pArray, unsigned int uLen)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < uLen - 1; i++)
    {
        for (j = 0; j < uLen - i - 1; j++)
        {
            if (pArray[j] > pArray[j + 1])
            {
                temp = pArray[j];
                pArray[j] = pArray[j + 1];
                pArray[j + 1] = temp;
            }
        }
    }
}
unsigned int binarySearch(int *pArray, unsigned int uArraySize, unsigned int uValue)
{
    unsigned int uLow = 0;
    unsigned int uHigh = uArraySize - 1;
    unsigned int uMid = 0;
    while (uLow <= uHigh)
    {
        uMid = (uLow + uHigh) / 2;
        if (pArray[uMid] == uValue)
        {
            return uMid;
        }
        else if (pArray[uMid] < uValue)
        {
            uLow = uMid + 1;
        }
        else
        {
            uHigh = uMid - 1;
        }
    }
    return 0xFFFF;
}
void Add(const char *p1, const char *p2, char *result)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int carry = 0;
    int sum = 0;
    int len1 = strlen(p1);
    int len2 = strlen(p2);
    int len = len1 > len2 ? len1 : len2;
    int len_result = len + 1;
    int arr1[len1];
    int arr2[len2];
    int arr_result[len_result];
    for (i = 0; i < len1; i++)
    {
        arr1[i] = p1[len1 - i - 1] - '0';
    }
    for (i = 0; i < len2; i++)
    {
        arr2[i] = p2[len2 - i - 1] - '0';
    }
    for (i = 0; i < len_result; i++)
    {
        arr_result[i] = 0;
    }
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            sum = arr1[i] + arr2[j] + carry;
            if (sum >= 10)
            {
                carry = 1;
                sum = sum - 10;
            }
            else
            {
                carry = 0;
            }
            arr_result[i + j] = sum;
        }
        if (carry == 1)
        {
            arr_result[i + j] = 1;
        }
    }
    for (i = 0; i < len_result; i++)
    {
        result[i] = arr_result[len_result - i - 1] + '0';
    }
}
void SPRINTF(char* szBuffer, char* szPattern, char** args) {
    int i = 0;
    int j = 0;
    int k = 0;
    int len = strlen(szPattern);
    int len_args = 0;
    int len_buffer = 0;
    int len_arg = 0;
    int len_arg_buffer = 0;
    int len_arg_pattern = 0;
    int len_arg_pattern_buffer = 0;
}
class cWindow{
public:
    int Left;
    int Right;
    int Top;
    int Bottom;
    cWindow()
    {
        Left = 0;
        Right = 0;
        Top = 0;
        Bottom = 0;
    }
    cWindow(const cWindow& obj)
    {
        Left = obj.Left;
        Right = obj.Right;
        Top = obj.Top;
        Bottom = obj.Bottom;
    }
};
class cHint : public cWindow
{
public:
    tString sCaption;
    cHint()
    {
        sCaption = "";
    }
    cHint(const cHint& obj)
    {
        Left = obj.Left;
        Right = obj.Right;
        Top = obj.Top;
        Bottom = obj.Bottom;
        sCaption = obj.sCaption;
    }
};
class cBitButton : public cWindow
{
public:
    tBitmap aBitmap;
    cBitButton()
    {
        aBitmap = NULL;
    }
    cBitButton(const cBitButton& obj)
    {
        Left = obj.Left;
        Right = obj.Right;
        Top = obj.Top;
        Bottom = obj.Bottom;
        aBitmap = obj.aBitmap;
    }
};
     int main() {
        //checkbit
        unsigned int uValue = 0xFF;
        printf("%d\n", CheckBit(uValue));
        //reverse
        char str[] = "Hello World!";
        reverse(str);
        printf("%s\n", str);
        //mirror
        unsigned char pImage[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
        VMirror(pImage);
        printf("%x %x %x %x %x %x %x %x\n", pImage[0], pImage[1], pImage[2], pImage[3], pImage[4], pImage[5], pImage[6],
               pImage[7]);
        //convert
        int sValue = -123;
        char pBuffer[10];
        Conv(sValue, pBuffer);
        printf("%s\n", pBuffer);
        //stack
        int arr[8] = {0};
        push(arr, 1);
        //pop
        printf("%d\n", pop(arr));
        //print array
        print_array(arr);
        //print array char
        char arr_char[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        print_array_char(arr_char);
        //check if empty
        printf("%d\n", isEmpty(arr));
        //check if full
        printf("%d\n", isFull(arr));
        //check if in array
        printf("%d\n", isInArray(arr, 1));
        //bubble sort
        int arr_bubble[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        bubbleSort(arr_bubble, 8);
        print_array(arr_bubble);
        //binary search
        int arr_binary[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        bubbleSort(arr_binary, 8);
        printf("%d\n", binarySearch(arr_binary, 8, 3));
        //add
        char str1[] = "123456789";
        char str2[] = "987654321";
        char result[20];
        Add(str1, str2, result);
        printf("%s\n", result);
        //sprintf
        char szBuffer[20];
        char szPattern[] = "Hello %s!";
        char *args[] = {"World"};
        sprintf(szBuffer, szPattern, args);
        printf("%s\n", szBuffer);
        //cWindow
        cWindow obj;
        printf("%d %d %d %d\n", obj.Left, obj.Right, obj.Top, obj.Bottom);
        //cHint
        cHint obj_hint;
        printf("%d %d %d %d %s\n", obj_hint.Left, obj_hint.Right, obj_hint.Top, obj_hint.Bottom, obj_hint.sCaption);
        //cBitButton
        cBitButton obj_bitbutton;
        printf("%d %d %d %d %x\n", obj_bitbutton.Left, obj_bitbutton.Right, obj_bitbutton.Top, obj_bitbutton.Bottom,
               obj_bitbutton.aBitmap);
        return 0;
    }
