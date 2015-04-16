CREATE TABLE [dbo].[Flight]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [Number] NCHAR(10) NULL, 
    [Origin] NCHAR(10) NULL, 
    [Destination] NCHAR(10) NULL, 
    [DepartureTime] DATETIME2 NULL, 
    [AirplaneId] INT NULL, 
    CONSTRAINT [FK_Flight_Airplane] FOREIGN KEY ([AirplaneId]) REFERENCES [Airplane]([Id])
)
