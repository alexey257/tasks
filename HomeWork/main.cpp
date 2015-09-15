//  ������� ����������� ���������
// -------------------------------
// �������:
// �������� ���������, ������� ������ ���������� ���������.
// ������������ ������ (� ����������) ��� �������������� ������������ a, b, c.
// ��������� ������� ��� ������� ��������� (���, ����), "������� ���",
// ���� �� ��� ��� "���������� ����� �������",
// ���� �������� ����� �������� x (a = 0, b = 0, c = 0).
// ���������� ��� �������� �������� ������.

#include <Windows.h>
#include <iostream>
#include <cmath>
#include <clocale>

//

using namespace std;

void show_result(const double* result, int qty)
{
  if(qty ==0) cout << "��� �������" << endl;
  else if(qty == 100500) cout << "����������� ����� �������" << endl;
  else
    for(int i = 0; i < qty; i++)
    {
      cout << "������� " << (i + 1) << " ����� " << result[i] << endl;
    }
  return;
}


//-->
// ������� ������ ������� �� �����
//assume whether coeffs of equation approx equal to zero
//so counted as value in a set
//solution is assigned as a number, assuming coeffs equal to zero
void solve_equation(double* result, int* qty, double a, double b, double c) {
  //

  //~equal to zero
  const double EPS = 1e-10;

  *qty = 0;

  if((fabs(a) < EPS)&&(fabs(b) < EPS))
  {
    result[*qty] = 100500;
    *qty = 100500;
    return; //over 100500 answers
  }

  if(fabs(c) < EPS)
  {
      result[(*qty)++] = 0;
      if(fabs(a) > EPS)
      {
          result[(*qty)++] = -b/a;
      }
      return;
  }
  else
  {
      if((fabs(a) < EPS) && (fabs(b) > EPS))
      {
          result[(*qty)++] = -c/b;
      }
      else if((fabs(a) > EPS) && (fabs(b) < EPS))
      {
          double temp_result = -c/a;
          if(temp_result > EPS)
          {
              result[(*qty)++] = sqrt(temp_result);
              result[(*qty)++] = -result[*qty - 1];
          }
      }
      else
      {
        double D = b*b - 4*a*c;
        if(fabs(D) < EPS)
        {
            result[(*qty)++] = -(b/(2*a));
            result[(*qty)++] = result[(*qty)-1];
            return;
        }
        if(D < (-EPS))
        {
            //result[*qty] = 0;
            *qty = 0;
            return;
        }
        if(D > EPS)
        {
            result[(*qty)++] = -(b - sqrt(D))/(2*a);
            result[(*qty)++] = -(b + sqrt(D))/(2*a);
            return;
        }
    }
  }
}
//<--

int main() {
  //-->

//  setlocale(LC_ALL,"Russian");
SetConsoleCP (1251);
SetConsoleOutputCP(1251);
  cout << "������� ����������� ���������" << endl;
  cout << "� �������������� �������\n" << endl;
  cout << "������� ������������ ax^2+bx+c=0:\n" << endl;
  // ������������ ����������� ���������
  double a, b, c;
  // a*x^2 + b*x + c = 0
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "c = ";
  cin >> c;
  cout << endl;

  double result[5];
  int qty;

  // ����� ������� ������� ����������� ���������
  solve_equation(result, &qty, a, b, c);
  show_result(result, qty);
  //<--

  return 0;
}
