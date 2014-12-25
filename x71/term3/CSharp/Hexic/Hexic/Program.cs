// Eugene Auduchinok, 2014

using System;
using System.Collections.Generic;
using System.Linq;

namespace Hexic
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int size = 10;
			int colors = 5;
			int turns = 10;

			Hexic game = new Hexic (size, colors, turns);
		
			game.Draw ();
			game.Play ();
			game.Draw ();
		}
	}

	public class Hexic
	{
		class Cell
		{
			public int column;
			public int row;

			public bool exists;
			public int color;

			public bool visited;
		}

		int size;
		int colors;
		int turns;
		int score;
		Cell[,] field;
		Random rnd = new Random();

		public Hexic(int size, int colors, int turns)
		{
			this.size = size;
			this.colors = colors;
			this.turns = turns;
			this.field = new Cell[size, size - 1]; // (column, row)

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					Cell cell = new Cell ();
					cell.column = i;
					cell.row = j;

					if (i % 2 == 0 && j == size - 2) {
						cell.exists = false;
					} else {
						cell.color = rnd.Next (colors);
						cell.exists = true;
					}

					cell.visited = false;

					field [i, j] = cell;
				}
			}
		}

		public void Draw()
		{
			Console.WriteLine ("");
			for (int j = 0; j < size - 1; j++) {
				for (int i = 0; i < size; i++) {
					if (field [i, j].exists)
						Console.Write (field [i, j].color + "\t");
					else
						Console.Write ("\t");
				}
				Console.WriteLine ("");
			}
		}

		bool IsEven(int x) {
			return x % 2 == 0;
		}

		bool IsOdd(int x) {
			return x % 2 != 0;
		}

		int pow(int x, int n)
		{
			int result = x;

			for (int i = 1; i < n; i++) {
				result *= x;
			}

			return result;
		}

		void FindRepetitions()
		{
			int removedCount = 0;

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					Cell cell = field [i, j];

					if (!cell.exists) {
						continue;
					}

					foreach (Cell cellToRefresh in field) {
						cellToRefresh.visited = false;
					}

					Queue<Cell> next = new Queue<Cell> ();
					next.Enqueue (cell);

					Queue<Cell> toRemove = new Queue<Cell> ();

					while (next.Count > 0) {
						var current = next.Dequeue ();

						if (current.visited) {
							continue;
						}

						current.visited = true;
						toRemove.Enqueue (current);
//						Console.WriteLine (toRemove.Count);

						var sameNeighbours = Neighbours (current.column, current.row).Where (x => x.color == cell.color).ToList ();

						foreach (Cell same in sameNeighbours) {
							if (same.visited) {
								continue;
							}

							next.Enqueue (same);
						}
					}


					if (toRemove.Count >= 3) {
						RemoveCells (toRemove);
						removedCount += toRemove.Count;

//						i = 0;
//						j = 0;
					}
				}
			}

			if (removedCount > 0) {
				score += 3 * pow (2, removedCount - 3);
			}
		}

		void RemoveCells(Queue<Cell> toRemove)
		{
			while (toRemove.Count > 0) {
				Cell cell = toRemove.Dequeue ();

				int column = cell.column;
				int row = cell.row;

				if (row == 0) {
					field [column, row] = CreateCell (column, row);
					continue;
				}

				int rowToMove = row - 1;
				while (rowToMove >= 0 && toRemove.Contains (field [column, rowToMove])) {
					rowToMove--;
				}

				if (rowToMove == -1) {
					field [column, row] = CreateCell (column, row);
				} else {
					field [column, row] = field [column, rowToMove];
					toRemove.Enqueue (field [column, rowToMove]);
				}
			}
		}

		Cell CreateCell(int column, int row)
		{
			Cell cell = new Cell ();

			cell.column = column;
			cell.row = row;
			cell.color = rnd.Next (colors);
			cell.exists = true;
			cell.visited = false;

			return cell;
		}

		List<Cell> Neighbours(int col, int row)
		{
			List<Tuple<int, int>> neighbours = new List<Tuple<int,int>> {
				Tuple.Create (col, row - 1),
				Tuple.Create (col, row + 1),
				Tuple.Create (col - 1, row),
				Tuple.Create (col + 1, row)
			};

			if (col % 2 == 0) {
				neighbours.Add (Tuple.Create (col - 1, row + 1));
				neighbours.Add (Tuple.Create (col + 1, row + 1));
			} else {
				neighbours.Add (Tuple.Create (col - 1, row - 1));
				neighbours.Add (Tuple.Create (col + 1, row - 1));
			}

			neighbours = neighbours.Where (x => x.Item1 >= 0 && x.Item2 >= 0)
				.Where (x => x.Item1 < size && x.Item2 < size - 2)
				.ToList ();


			return neighbours.Select (x => field [x.Item1, x.Item2]).ToList ();
		}

		Cell[] CellsToRotate(int col, int row)
		{
			Cell[] cells = new Cell[3];

			if (col % 2 == 0) {
				if (row % 2 == 0) {
					cells [0] = field [col, row / 2];
					cells [1] = field [col + 1, row / 2 + 1];
					cells [2] = field [col + 1, row / 2];
				} else {
					cells [0] = field [col, row / 2];
					cells [1] = field [col, row / 2 + 1];
					cells [2] = field [col + 1, row / 2 + 1];
				}
			} else {
				if (row % 2 == 0) {
					cells [0] = field [col, row / 2];
					cells [1] = field [col, row / 2 + 1];
					cells [2] = field [col + 1, row / 2];
				} else {
					cells [0] = field [col, row / 2 + 1];
					cells [1] = field [col + 1, row / 2 + 1];
					cells [2] = field [col + 1, row / 2];
				}
			}

			return cells;
		}

		void Rotate(Cell[] cells)
		{
			var tmp = cells [0].color;

			cells [0].color = cells [2].color;
			cells [2].color = cells [1].color;
			cells [1].color = tmp;
		}

		void RotateBackwards (Cell[] cells)
		{
			var tmp = cells [0].color;

			cells [0].color = cells [1].color;
			cells [1].color = cells [2].color;
			cells [2].color = tmp;
		}

		void MakeTurn()
		{
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < (size - 2) * 2 - 1; j++) {
					int currentScore = score;

					var cells = CellsToRotate (i, j);
					Rotate (cells);

					FindRepetitions ();

					if (currentScore != score) {
						return; 
					} else {
						RotateBackwards (cells);
					}
				}
			}
		}

		public void Play()
		{
			FindRepetitions ();

//			Console.WriteLine (score);

			score = 0;


			Console.WriteLine ("Start game.");

			for (int turn = 0; turn < turns; turn++) {
				MakeTurn ();
			}

			Console.WriteLine ("Score: " + score);
		}
	}
}

// Already spent about fourteen hours.