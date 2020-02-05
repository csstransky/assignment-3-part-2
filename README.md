# assignment-3-part-2



Code Examples:
```
IntColumn* ic = new IntColumn(1, 3, 4);
FloatColumn* fc = new FloatColumn(1.34, 33.0, 0.4);
DataFrame* df = new DataFrame(ic, fc);
for(size_t ii = 0; ii < df->ncol(); ii++) {
    if (df->is_float_column(ii)) {
        for(size_t jj = 0; jj < df->nrow(); jj++) {
            float f = df->get_float(jj, ii);
            f += 5;
            df->set(jj, ii, f);
        }
    }
}
// This is also possible as well
for(size_t ii = 0; ii < df->ncol(); ii++) {
    Column* c = df->get_column(ii);
    if (c->is_float_column()) {
        for(size_t jj = 0; jj < c->size(); jj++) {
            float f = c->get_float(jj);
            f += 5;
            c->set(jj, f);
        }
    }
}

// Adding a row to a dataframe
int new_int_value = 14;
float new_float_value = 2.3;
df->add_row();
df->set(df->nrow() - 1, 0, new_int_value);
df->set(df->nrow() - 1, 1, new_float_value);
```

```



```