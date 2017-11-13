/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"

void printArrayListEmployee(ArrayList* lista)
{
  int i;
  Employee* pAux;
  for(i=0;i<lista->len(lista);i++)
  {
      pAux = (Employee*)lista->get(lista,i);
      printEmployee(pAux);
  }
}

int Prueba(void);

int main(void)
{
        /*startTesting(1);        //al_newArrayList
        startTesting(2);        //al_add
        startTesting(3);        //al_deleteArrayList
        startTesting(4);        //al_len
        startTesting(5);      //al_get
        startTesting(6);        //al_contains
        startTesting(7);         //al_set
        startTesting(8);       //al_remove
        startTesting(9);        //al_clear
        startTesting(10);       //al_clone
        startTesting(11);      //al_push
        startTesting(12);       //al_indexOf
        startTesting(13);       //al_isEmpty
        startTesting(14);       //al_pop
        startTesting(15);       //al_subList
        startTesting(16);       //al_containsAll
        startTesting(17);*/   //al_sort
        Prueba();
    return 0;
}

int Prueba(void)
{
    //Genero empleados para usar en el ArrayList
    Employee* p0 = newEmployee(14, "Nicolas" ,"Ferrero", 500,1);
    Employee* p1 = newEmployee(15, "Juan" ,"Perez", 250,2);
    Employee* p2 = newEmployee(16, "Carlos" ,"Lopez", 125,3);
    Employee* p3 = newEmployee(17, "Claudio" ,"Diaz", 350,4);
    Employee* p4 = newEmployee(18, "Jose","Gimenez", 275,2);

    printEmployee(p0);
    printEmployee(p1);
    printEmployee(p2);
    printEmployee(p3);
    printEmployee(p4);

    printf("\r\nCargo ArraList...\r\n");
    ArrayList* listaEmpleados = al_newArrayList();
    listaEmpleados->add(listaEmpleados,p0);
    listaEmpleados->add(listaEmpleados,p1);
    listaEmpleados->add(listaEmpleados,p2);
    listaEmpleados->add(listaEmpleados,p3);
    listaEmpleados->add(listaEmpleados,p4);
    printArrayListEmployee(listaEmpleados);
    printf("Cantidad de elementos es: %d",listaEmpleados->len(listaEmpleados));

    printf("\r\n\nRemuevo p2\r\n");
    listaEmpleados->remove(listaEmpleados,2);
    printArrayListEmployee(listaEmpleados);
    printf("Cantidad de elementos es: %d",listaEmpleados->len(listaEmpleados));

    printf("\r\n\nContiene p0 ?\r\n");
    if(listaEmpleados->contains(listaEmpleados,p0))
    {
       printf("SI");
    }
    else
    {
       printf("NO");
    }

    printf("\r\nContiene p2 ?\r\n");
    if(listaEmpleados->contains(listaEmpleados,p2))
    {
       printf("SI");
    }
    else
    {
       printf("NO");
    }

    printf("\r\n\nAgrego p2 en la posicion 1\r\n");
    listaEmpleados->set(listaEmpleados,1,p2); // vuelvo a agregar p2
    printArrayListEmployee(listaEmpleados);
    printf("Cantidad de elementos es: %d",listaEmpleados->len(listaEmpleados));

    printf("\r\n\nClonamos array\r\n");
    ArrayList* listaEmpleadosAux = listaEmpleados->clone(listaEmpleados);
    printf("Lista original:%p\r\n",listaEmpleados);
    printArrayListEmployee(listaEmpleados);

    printf("\nLista Clonada:%p\r\n",listaEmpleadosAux);
    printArrayListEmployee(listaEmpleadosAux);

    listaEmpleadosAux->sort(listaEmpleadosAux,compareEmployee,1);
    printf("\nLista Clonada Ordenada por salario (UP):%p\r\n",listaEmpleadosAux);
    printArrayListEmployee(listaEmpleadosAux);

    listaEmpleadosAux->sort(listaEmpleadosAux,compareEmployee,0);
    printf("\nLista Clonada Ordenada por salario (DOWN):%p\r\n",listaEmpleadosAux);
    printArrayListEmployee(listaEmpleados);

    printf("\r\nlista clonada contiene lista?:");
    if(listaEmpleados->containsAll(listaEmpleados,listaEmpleadosAux))
    {
       printf("SI");
    }
    else
    {
       printf("NO");
    }

    printf("\r\n\r\nPosicion de p2:");
    int index = listaEmpleados->indexOf(listaEmpleados,p2);
    printf("%d\r\n",index);
    printf("\r\nPosicion de p1:");
    index = listaEmpleados->indexOf(listaEmpleados,p1);
    printf("%d\r\n",index);

    printf("\r\n\r\nHacemos push de p1 en la posicion 2\r\n");
    listaEmpleados->push(listaEmpleados,2,p1);
    printArrayListEmployee(listaEmpleados);
    printf("Cantidad de elementos es: %d",listaEmpleados->len(listaEmpleados));

    printf("\r\n\nObtenemos sub-lista de 1 a 3\r\n");
    ArrayList* subLista = listaEmpleados->subList(listaEmpleados,1,3);
    printArrayListEmployee(subLista);
    printf("Cantidad de elementos es: %d",subLista->len(subLista));

    printf("\r\n\r\nHacemos pop de p1\r\n");
    listaEmpleados->pop(listaEmpleados,1);
    printArrayListEmployee(listaEmpleados);
    printf("Cantidad de elementos es: %d",listaEmpleados->len(listaEmpleados));

    printf("\r\n\nClear array\r\n");
    listaEmpleados->clear(listaEmpleados);
    printArrayListEmployee(listaEmpleados);
    printf("Cantidad de elementos es: %d",listaEmpleados->len(listaEmpleados));

    printf("\r\n\nEsta vacio?\r\n");
    if(listaEmpleados->isEmpty(listaEmpleados))
    {
       printf("SI");
    }
    else
    {
       printf("NO");
    }

    // Test expansion/contraccion del size
    printf("\r\n\r\nTest Resize/Contract\r\n");
    int j;
    for(j=0; j<1100; j++)
    {
      Employee* pAux = malloc(sizeof(Employee));
      sprintf(pAux->name,"Juan %d",j);
      pAux->salary=j;
      listaEmpleados->add(listaEmpleados,pAux);
    }
    printf("Cantidad de elementos:%d\r\n",listaEmpleados->len(listaEmpleados));

    for(j=0; j<1100; j++)
    {
      listaEmpleados->pop(listaEmpleados,0);
    }
    printf("Cantidad de elementos:%d\r\n",listaEmpleados->len(listaEmpleados));

    printf("\r\nLibero memoria y termino\r\n");
    free(p0);
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    listaEmpleados->deleteArrayList(listaEmpleados);
    listaEmpleadosAux->deleteArrayList(listaEmpleadosAux);

    system("PAUSE");
    return 0;
}
