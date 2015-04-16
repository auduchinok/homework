CREATE TABLE [dbo].[Airplane]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [Type] NCHAR(50) NULL, 
    [PilotId] INT NULL, 
    [Number] NCHAR(10) NULL, 
    [Seats] INT NULL, 
    CONSTRAINT [FK_Airplane_Pilot] FOREIGN KEY ([PilotId]) REFERENCES [Pilot]([Id])
)
