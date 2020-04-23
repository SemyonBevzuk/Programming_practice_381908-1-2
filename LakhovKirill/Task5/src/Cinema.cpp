//
// Created by Kirill on 23.04.2020.
//

#include "../include/Cinema.h"
#include "../include/Connector.h"
Cinema::Cinema() {
    this->connector = Connector("cinema.db3", "sessions_template");
}

void Cinema::initDays() {
    this->connector.initTemplateTable();
    this->connector.initHallTable();
    this->connector.initSessionTable();
}
