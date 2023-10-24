CREATE TABLE students (
    id INTEGER UNIQUE NOT NULL,
    student_name TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER UNIQUE NOT NULL,
    house TEXT NOT NULL,
    head TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE assignments (
    id INTEGER UNIQUE NOT NULL,
    id_students TEXT NOT NULL,
    id_houses TEXT NOT NULL,
    PRIMARY KEY(id),
    FOREIGN KEY(id_students) REFERENCES students(id),
    FOREIGN KEY(id_houses) REFERENCES houses(id)
);