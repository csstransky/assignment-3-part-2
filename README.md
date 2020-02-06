# DataFrame API

Our DataFrame API is created in a flexible manner where there are multiple ways to complete tasks. It is recommended while using this API to strictly use the DataFrame
object as much as possible, ESPECIALLY when manipulating rows. 

Though this API can still handle specific manipulation of Columns if desired; extra care should be taken when using add_row(...) and remove_row(...) on a Column.

## DataFrame

A DataFrame is made of Columns. The cells inside the Column can be accessed by type with the following functions:

```
String* get_string(size_t row, size_t column);
bool get_bool(size_t row, size_t column);
int get_int(size_t row, size_t column);
float get_float(size_t row, size_t column);
```

Setting values is done with an overloaded `set(...)` function:

```
IntColumn* ic = new IntColumn(1, 2);
FloatColumn* fc = new FloatColumn(2.3, 43.3);
DataFrame* df = new DataFrame(ic, fc);
df->set(0, 0, 13);
df->set(0, 1, 2.2);

// NOTE: type for the set(...) function must be the same as the Column, or else an error will be thrown
df->set(0, 0, new String("error")); // this will cause an error
```

## Column

A Column can only be constructed strictly by its type. This is to ensure that each Column is strictly made of its type.  
Example:
```
IntColumn* ic = new IntColumn();
FloatColumn* fc = new FloatColumn();

// this constructor is not possible and will throw a compile error
Column* c = new Column(); // error
```
Headers for a Column can also be constructed with the Column or decorated later.  
Example:
```
String* header = new String("Numbers");
IntColumn* ic = new IntColumn(header, 1, 4, 5);

// It can also be decorated as well
BoolColumn* bc = new BoolColumn(0, 1, 0, 1);
bc->set_header(header);

// Because of the nature of StringColumn, if there are more than two cells and no header, then a nullptr must be used as the first argument
StringColumn* stc = new StringColumn(nullptr, new String("hello"), new String("bye"));

// The constructor still acts the same if there is a header though
StringColumn* stc2 = new StringColumn(header, new String("one"), new String("two"));
```
Getter and setter methods are made similiarily to how they're handled in a DataFrame, and type is enforced or else an error will be thrown.  
Example:
```
BoolColumn* sc = new BoolColumn(0, 1);
sc->get_bool(1);
sc->get_string(0); // throws an error
sc->set(0, 12); // throws an error
```
To ensure that the column is a specific type, a Boolean function can be used. This is done through overriding the function with each Column class.  
Example:
```
BoolColumn* sc = new BoolColumn(0, 1);
if (sc->is_bool_column()) {
    sc->get_bool(1);
}
if (sc->is_string_column()) {
    sc->get_string(0); // error avoided
}
```

## Code Examples

The following are examples of how the API can be used:
```
// Adding 5.0 to each float in the DataFrame
IntColumn* ic = new IntColumn(1, 3, 4);
FloatColumn* fc = new FloatColumn(1.34, 33.0, 0.4);
DataFrame* df = new DataFrame(ic, fc);
for(size_t ii = 0; ii < df->ncol(); ii++) {
    if (df->is_float_column(ii)) {
        for(size_t jj = 0; jj < df->nrow(); jj++) {
            float f = df->get_float(jj, ii);
            f += 5.0;
            df->set(jj, ii, f);
        }
    }
}

// This is also possible as well if you wish to explicitly use Column
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
```
```
// Adding a row to a dataframe
DataFrame* df = new DataFrame(new IntColumn(21), new FloatColumn(2.3));
DataFrame* new_row = new DataFrame(new IntColumn(14), new FloatColumn(2.3));
df->insert(df->ncol() - 1, new_row);

// This is also possible as well if you wish to decorate directly to the main dataframe
int new_int_value = 14;
float new_float_value = 2.3;
df->add_row();
df->set(df->nrow() - 1, 0, new_int_value);
df->set(df->nrow() - 1, 1, new_float_value);
```

```
// Querying for all rows with integer values "14" from Column 0 from the DataFrame
IntColumn sc = new IntColumn(14, 4, 14)
BoolColumn bc = new BoolColumn(0, 0, 1);
DataFrame* df = new DataFrame(sc, bc);
DataFrame* sub_df = df->query(0, 14);
df->print();
//  0    1
//  14   0
//  4    0
//  14   1
sub_df->print();
//  0    1
//  14   0
//  14   1  
delete df;
delete sub_df; // querying creates a new dataframe, so it must be deleted
delete sc;
delete bc; 
```