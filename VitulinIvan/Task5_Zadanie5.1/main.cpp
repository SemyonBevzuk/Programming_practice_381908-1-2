#include"TicketOffice.h"
#include "Cinema.h"

int main() {
    setlocale(LC_CTYPE, "Russian");
    TicketOffice to;
    to.AddSession("Film", DateTime(2020, 6, 10, 12, 0), 3);
    Cinema c(to);
    c.Start();
}