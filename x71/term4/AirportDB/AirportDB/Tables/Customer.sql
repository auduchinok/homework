CREATE TABLE [dbo].[Customer]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [FirstName] NCHAR(20) NULL, 
    [SecondName] NCHAR(20) NULL, 
    [PhoneNumber] NCHAR(20) NULL, 
    [BankCardNumber] NCHAR(20) NULL, 
    [PassportNumber] NCHAR(20) NULL
)
