CREATE TABLE students (
    id INTEGER UNIQUE,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER UNIQUE,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE assignments (
    id INTEGER UNIQUE,
    id_students INTEGER,
    id_houses INTEGER,
    PRIMARY KEY(id)
    FOREIGN KEY(id_students as students.id)
    FOREIGN KEY(id_houses as houses.id)
);