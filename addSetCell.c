void add(Matrix * m, int row, int col, int value){

    RowCol * r = m->row, * c = m->col; // берем головные узлы в массиве строк и столбцов
    if(r->index == -1){ // вставляем первый элемент в массиве индексов строк
        RowCol * tmp = (RowCol*)malloc(sizeof(RowCol));
        tmp->cell = (Data*)malloc(sizeof(Data));
        initData(tmp->cell);
        tmp->index = row;
        tmp->next = NULL;
        m->row = tmp;
        r = m->row;
    }
    else{
        if(findSameIndex(r, row) == true){ // если уже есть строка с таким индексом в массиве строк
            if(m->row->index != row) { // если головной узел не является добавляем(то есть он уже числится)
                while (true) {
                    if (r->next->index == row) {
                        break;
                    } else {
                        r = r->next;
                    }
                }
            }
        }else{ // если не нашлось такого индекса, то итерируемся до ближайшего места, куда можно поставить данный индекс
            /* нужно проверять:
             * 1) если можно сделать этот индекс головным узлом
             * 2) если этот индекс можно поставить в середину списка
             * 3) если этот индекс нужно поставить в самый конец списка
             * */
            while(true){
                if(m->row->index > row){ // проверка на то, если новый индекс претендует на головной узел
                    RowCol * tmp = (RowCol*)malloc(sizeof(RowCol));
                    tmp->cell = (Data*)malloc(sizeof(Data));
                    initData(tmp->cell);
                    tmp->index = row;
                    tmp->next = m->row;
                    m->row = tmp;
                    r = m->row;
                    break;
                }else{
                    while(true){
                        if(r->next != NULL){
                            if(r->next->index < row){
                                r = r->next;
                            }else{
                                break;
                            }
                        }else{
                            break;
                        }
                    }
                    RowCol * tmp = (RowCol*)malloc(sizeof(RowCol));
                    tmp->cell = (Data*)malloc(sizeof(Data));
                    initData(tmp->cell);
                    tmp->index = row;
                    if(r->next != NULL){
                        tmp->next = r->next;
                    }else{
                        tmp->next = NULL;
                    }
                    r->next = tmp;
                    r = r->next;
                    break;
                }
            }
        }
    }
    if(c->index == -1){ // вставляем первый элемент в массиве индексов столбцов
        RowCol * tmp = (RowCol*)malloc(sizeof(RowCol));
        tmp->cell = (Data*)malloc(sizeof(Data));
        initData(tmp->cell);
        tmp->index = col;
        tmp->next = NULL;
        m->col = tmp;
        c = m->col;
    }

    else{
        if(findSameIndex(c, col) == true){ // если уже есть такой индекс в массиве столбцов
            if(m->col->index != col) {
                while (true) {
                    if (c->next->index == col) {
                        break;
                    } else {
                        c = c->next;
                    }
                }
            }
        }else{ // если не нашлось такого индекса, то итерируемся до ближайшего места, куда можно поставить данный индекс
            /* нужно проверять:
             * 1) если можно сделать этот индекс головным узлом
             * 2) если этот индекс можно поставить в середину списка
             * 3) если этот индекс нужно поставить в самый конец списка
             * */
            while(true){
                if(m->col->index > col){ // проверка на то, если новый индекс претендует на головной узел
                    RowCol * tmp = (RowCol*)malloc(sizeof(RowCol));
                    tmp->cell = (Data*)malloc(sizeof(Data));
                    initData(tmp->cell);
                    tmp->index = col;
                    tmp->next = m->col;
                    m->col = tmp;
                    c = m->col;
                    break;
                }else{
                    while(true){
                        if(c->next != NULL){
                            if(c->next->index < col){ //
                                c = c->next;
                            }else{ // если нашелся такой узел, что его индекс меньше
                                break;
                            }
                        }else{
                            break;
                        }
                    }
                    RowCol * tmp = (RowCol*)malloc(sizeof(RowCol));
                    tmp->cell = (Data*)malloc(sizeof(Data));
                    initData(tmp->cell);
                    tmp->index = col;
                    if(c->next != NULL){ // проверка на то, если добавляемый узел не станет последним после добавление(то есть есть еще какие-то индексы, которые больше чем добавляемый)
                        tmp->next = c->next;
                    }else{
                        tmp->next = NULL;
                    }
                    c->next = tmp;
                    c = c->next;
                    break;
                }
            }
        }
    }
