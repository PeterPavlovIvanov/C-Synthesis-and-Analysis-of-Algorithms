USE PhoneBook
GO

ALTER TABLE PERSONS
DROP CONSTRAINT FK_PERSONS_CITY_ID 
ALTER TABLE PHONE_NUMBERS
DROP CONSTRAINT FK_PHONE_NUMBERS_PERSON_ID, FK_PHONE_NUMBERS_PHONE_TYPE_ID

TRUNCATE TABLE PHONE_NUMBERS
TRUNCATE TABLE PHONE_TYPES
TRUNCATE TABLE PERSONS
TRUNCATE TABLE CITIES
GO

ALTER TABLE PERSONS
ADD CONSTRAINT FK_PERSONS_CITY_ID FOREIGN KEY (CITY_ID) REFERENCES CITIES(ID)
ALTER TABLE PHONE_NUMBERS
ADD CONSTRAINT FK_PHONE_NUMBERS_PERSON_ID FOREIGN KEY (PERSON_ID) REFERENCES PERSONS(ID),
CONSTRAINT FK_PHONE_NUMBERS_PHONE_TYPE_ID FOREIGN KEY (PHONE_TYPE_ID) REFERENCES PHONE_TYPES(ID)

INSERT CITIES
(UPDATE_COUNTER, CITY_NAME, REGION)
VALUES 
(0,'Sofia','Sofia Central Province'),
(0,'Plovdiv','Plovdiv Province'),
(0,'Varna','Varna Province'),
(0,'Burgas','Burgas Province'),
(0,'Ruse','Ruse Province'),
(0,'Stara Zagora','Stara Zagora Province'),
(0,'Pleven','Pleven Province'),
(0,'Sliven','Sliven Province'),
(0,'Dobrich','Dobrich Province'),
(0,'Shumen','Shumen Province')
GO

INSERT PHONE_TYPES
(UPDATE_COUNTER, PHONE_TYPE)
VALUES 
(0,'Home'),
(0,'Mobile'),
(0,'Business')
GO

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Aleksandar', 'Aleksandrov', 'Georgiev', '1234567890', 	(SELECT ID FROM CITIES WHERE CITY_NAME = 'Sofia'), 'some address')
	INSERT PHONE_NUMBERS
	(UPDATE_COUNTER, PERSON_ID, PHONE_TYPE_ID, NUMBER)
	VALUES
	(0,(SELECT ID FROM PERSONS WHERE UCN = '1234567890'),1,'0876543210')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Georgi', 'Georgiev', 'Aleksandrov', '0987654321', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Pleven'), 'some address')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Martin', 'Martinov', 'Dimitrov', '2244668800', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Ruse'), 'some address')
	INSERT PHONE_NUMBERS
	(UPDATE_COUNTER, PERSON_ID, PHONE_TYPE_ID, NUMBER)
	VALUES
	(0,(SELECT ID FROM PERSONS WHERE UCN = '2244668800'),1,'0896523219')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Dimityr', 'Dimitrov', 'Martinov', '0099773377', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Varna'), 'some address')
	INSERT PHONE_NUMBERS
	(UPDATE_COUNTER, PERSON_ID, PHONE_TYPE_ID, NUMBER)
	VALUES
	(0,(SELECT ID FROM PERSONS WHERE UCN = '0099773377'),3,'0834423559')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Ivan', 'Dimitrov', 'Ivanov', '3927830281', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Ruse'), 'some address')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Daniel', 'Martinov', 'Nikolov', '2930492839', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Pleven'), 'some address')
	INSERT PHONE_NUMBERS
	(UPDATE_COUNTER, PERSON_ID, PHONE_TYPE_ID, NUMBER)
	VALUES
	(0,(SELECT ID FROM PERSONS WHERE UCN = '2930492839'),3,'0833434334')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Nikola', 'Danielov', 'Aleksandrov', '0172637402', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Plovdiv'), 'some address')
	INSERT PHONE_NUMBERS
	(UPDATE_COUNTER, PERSON_ID, PHONE_TYPE_ID, NUMBER)
	VALUES
	(0,(SELECT ID FROM PERSONS WHERE UCN = '0172637402'),3,'0875322259')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Kaloyan', 'Borisov', 'Kaloynov', '7483920172', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Sofia'), 'some address')
	INSERT PHONE_NUMBERS
	(UPDATE_COUNTER, PERSON_ID, PHONE_TYPE_ID, NUMBER)
	VALUES
	(0,(SELECT ID FROM PERSONS WHERE UCN = '7483920172'),1,'0828855922')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Viktor', 'Petrovich', 'Barinov', '6748302839', (SELECT ID FROM CITIES WHERE CITY_NAME = 'plovdiv'), 'some address')
	INSERT PHONE_NUMBERS
	(UPDATE_COUNTER, PERSON_ID, PHONE_TYPE_ID, NUMBER)
	VALUES
	(0,(SELECT ID FROM PERSONS WHERE UCN = '6748302839'),2,'0877773559')
COMMIT TRAN;

BEGIN TRAN
	INSERT PERSONS
	(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
	VALUES
	(0, 'Vikoriq', 'Dimitrova', 'Nikolova', '5743827502', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Varna'), 'some address')
	INSERT PHONE_NUMBERS
	(UPDATE_COUNTER, PERSON_ID, PHONE_TYPE_ID, NUMBER)
	VALUES
	(0,(SELECT ID FROM PERSONS WHERE UCN = '5743827502'),1,'0835234559')
COMMIT TRAN;

INSERT PERSONS
(UPDATE_COUNTER, FIRST_NAME, MIDDLE_NAME, LAST_NAME, UCN, CITY_ID, PERSONS.ADDRESS)
VALUES
(0, 'Simona', 'Borisova', 'Petrova', '5748392738', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Shumen'), 'some address'),
(0, 'Raq', 'Georgieva', 'Aleksandrova', '3234234234', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Shumen'), 'some address'),
(0, 'Maria', 'Martinova', 'Dimitrova', '7654563445', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Burgas'), 'some address'),
(0, 'Gabriela', 'Dimitrova', 'Borisova', '5435354232', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Burgas'), 'some address'),
(0, 'Borislava', 'Nikolova', 'Borisova', '5655688989', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Stara Zagora'), 'some address'),
(0, 'Nina', 'Gabrielova', 'Petrova', '1212123131', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Stara Zagora'), 'some address'),
(0, 'Ioana', 'martinova', 'Nencheva', '4232342343', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Sliven'), 'some address'),
(0, 'Lazar', 'Simeonov', 'Dimitrov', '4578317632', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Sofia'), 'some address'),
(0, 'Martin', 'Danielov', 'Petrov', '4234623421', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Sliven'), 'some address'),
(0, 'Dariq', 'Spasova', 'Aleksandrova', '8254261389', (SELECT ID FROM CITIES WHERE CITY_NAME = 'Sofia'), 'some address')
GO

UPDATE PERSONS
SET ADDRESS = 'new address'
WHERE CITY_ID > 5
GO

UPDATE PHONE_NUMBERS
SET PHONE_TYPE_ID = 3
WHERE PHONE_TYPE_ID % 2 = 0 AND PHONE_TYPE_ID != 8
GO

UPDATE PHONE_TYPES
SET PHONE_TYPE = 'Nokia' + CAST(ID AS varchar)
WHERE PHONE_TYPE = 'Samsung Galaxy S20 FE'
GO

SELECT * FROM CITIES
SELECT * FROM PHONE_TYPES
SELECT * FROM PERSONS
SELECT * FROM PHONE_NUMBERS
