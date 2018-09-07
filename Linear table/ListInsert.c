// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度-1
Status ListInsert(SqList *L, int i, ElemType e){
    int k;

    if(L->length == MAXSIZE){
        return ERROR;
    } // 顺序线性表已经满了
    if(i < 1 || i > L->length+1){
        return ERROR;
    } // 当i不在范围内时
    if (i <= L->length){
        for( k = L->length-1; k >= i-1; k--){
            L->data[k+1] = L->data[k];
        }
    } // 若插入数据位置不在表尾
    L->data[i-1] = e; // 将新元素插入
    L->length++;

    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e){
    int k;
    if(L->length == 0){
        return ERROR;
    }
    if(i < 1 || i > L->length){
        return ERROR;
    }

    *e = L->data[i-1];

    if(i < L->length){
        for(k = i; k < L->length; k++){
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;

}
