void add(Matrix * m, int row, int col, int value){

    RowCol * r = m->row, * c = m->col; // берем головные узлы в массиве строк и столбцов
    if(findTheSameCell(r, c, row, col, value) == true){
        return;
    }
    RowCol * tmp_row = (RowCol*)malloc(sizeof(RowCol));
    tmp_row->cell = (Data*)malloc(sizeof(Data));
    initData(tmp_row->cell);
    tmp_row->index = row;
    if(r->index == -1){ // вставляем первый элемент в массиве индексов строк
        tmp_row->next = NULL;
        m->row = tmp_row;
        r = m->row;
    }
    else{
        if(findSameIndex(r, row) == true){ // если уже есть строка с таким индексом в массиве строк
            if(m->row->index != row) { // если головной узел не является добавляем(то есть он уже числится)
                while (true) {
                    if (r->index == row) {
                        break;
                    } else {
                        r = r->next;
                    }
                }
            }
        }else{
            while(true){
                if(m->row->index > row){ // проверка на то, если новый индекс претендует на головной узел
                    tmp_row->next = m->row;
                    m->row = tmp_row;
                    r = m->row;
                    break;
                }else{
                    while(true){
                        if(r->next != NULL){
                            if(r->index < row){
                                r = r->next;
                            }else{
                                break;
                            }
                        }else{
                            break;
                        }
                    }
                    if(r->next != NULL){
                        tmp_row->next = r->next;
                    }else{
                        tmp_row->next = NULL;
                    }
                    r->next = tmp_row;
                    r = r->next;
                    break;
                }
            }
        }
    }
    RowCol * tmp_col = (RowCol*)malloc(sizeof(RowCol));
    tmp_col->cell = (Data*)malloc(sizeof(Data));
    initData(tmp_col->cell);
    tmp_col->index = col;
    if(c->index == -1){ // вставляем первый элемент в массиве индексов столбцов
        tmp_col->next = NULL;
        m->col = tmp_col;
        c = m->col;
    }

    else{
        if(findSameIndex(c, col) == true){ // если уже есть такой индекс в массиве столбцов
            if(m->col->index != col) {
                while (true) {
                    if (c->index == col) {
                        break;
                    } else {
                        c = c->next;
                    }
                }
            }
        }else{
            while(true){
                if(m->col->index > col){ // проверка на то, если новый индекс претендует на головной узел
                    tmp_col->next = m->col;
                    m->col = tmp_col;
                    c = m->col;
                    break;
                }else{
                    while(true){
                        if(c->next != NULL){
                            if(c->index < col){ //
                                c = c->next;
                            }else{ // если нашелся такой узел, что его индекс меньше
                                break;
                            }
                        }else{
                            break;
                        }
                    }
                    if(c->next != NULL){ // проверка на то, если добавляемый узел не станет последним после добавление(то есть есть еще какие-то индексы, которые больше чем добавляемый)
                        tmp_col->next = c->next;
                    }else{
                        tmp_col->next = NULL;
                    }
                    c->next = tmp_col;
                    c = c->next;
                    break;
                }
            }
        }
    }
    //после того, как нашлись нужные столбец и строка, начинаем сканировать данные для добавления
    Data * prvek = (Data*)malloc(sizeof(Data));
    prvek->row = row;
    prvek->col = col;
    prvek->right = NULL;
    prvek->down = NULL;
    prvek->data = value;
    /* проверяем если элемент, который я добавляю в матрицу становится первым в СТРОКЕ, а это значит если номер столбца добавляемого элемента < уже добавленный элемент в таблице */

    if(r->cell->col > prvek->col || r->cell->col == -1){ // если добавляемый элемент становится первым в СТРОКЕ
        if(r->cell != NULL){
            if(r->cell->row != -1){
                prvek->right = r->cell; // присваиваем новому элементу указатель на следующий элемент в таблице
            }
        }
        r->cell = prvek;
    }else{ // если добавляемый элемент не становится первым в СТРОКЕ
        while(true){
            if(r->cell != NULL){
                if(r->cell->col < prvek->col && r->cell->right != NULL){// пока не найдем такой значение в матрице, у которой значение столбца будет больше добавляемого или если добавляемое значение будет последним
                    r->cell = r->cell->right;
                }else{ // если нашелся такой элемент или закончился список
                    break;
                }
            }else{
                break;
            }
        }
        if(r->cell->right != NULL){
            prvek->right = r->cell->right;
        }
        r->cell->right = prvek;
    }

    if(c->cell->row > prvek->row || c->cell->row == -1){ // если добавляемый элемент становится первым в СТОЛБЦЕ
        if(c->cell != NULL){ // то есть если элемент, который до этого стоял на первом месте уже указывал на какой то элемент внизу
            if(c->cell->row != -1){
                prvek->down = c->cell;
            }
        }
        c->cell = prvek;
    }else{ // если добавляемый элемент не становится первым в СТОЛБЦЕ
        while(true){
            if(c->cell != NULL){
                if(c->cell->row < prvek->row && c->cell->down != NULL){ // пока не найдем такой значение в матрице, у которой значение столбца будет больше добавляемого или если добавляемое значение будет последним
                    c->cell = c->cell->down;
                }else{ // если нашелся такой элемент или закончился список
                    break;
                }
            }else{
                break;
            }
        }
        if(c->cell->down != NULL){
            prvek->down = c->cell->down;
        }
        c->cell->down = prvek;
    }
}
