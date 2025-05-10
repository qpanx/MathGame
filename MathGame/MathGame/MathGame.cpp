#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enMath {
	Add = 1, Subtract = 2, Multiplication = 3, Division =4 , MixOP = 5
};
enum enLevel {
	Easy = 1, Medium = 2, Hard = 3, Mix = 4
};

int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F"); 
	else
	{
		system("color 4F"); 
		cout << "\a"; 
	}
}
int SimpleCalculator(int Number1, int Number2, enMath OpType) {
	switch (OpType) {
	case enMath::Add:
		return Number1 + Number2;
	case enMath::Subtract:
		return Number1 - Number2;
	case enMath::Multiplication:
		return Number1 * Number2;
	case enMath::Division:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

string GetOpTypeSymbol(enMath OpType) {
	switch (OpType) {
	case enMath::Add:
		return "+";
	case enMath::Subtract:
		return "-";
	case enMath::Multiplication:
		return "*";
	case enMath::Division:
		return "/";
	default:
		return "Mix";
	}
}

string GetQuestionLevelText(enLevel QuestionLevel) {
	string arrQuestionLevelText[4] = { "Easy", "Medium" , "Hard" , "Mix" };
	return arrQuestionLevelText[QuestionLevel - 1];
}

short ReadHowManyQestions() {
	short NumberQues = 0;
	do
	{
		cout << "How Many Questions do you want to answer? ";
		cin >> NumberQues;
	} while (NumberQues < 1 || NumberQues > 10);

	return NumberQues;
}

enLevel ReadQuestionsLevel() {
	short NumUser ;
	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Medidum , [3] Hard  , [4] Mix ? ";
		cin >> NumUser;
	} while (NumUser < 0 || NumUser > 4);

	return (enLevel)NumUser;
}

enMath ReadOperationType() {
	short OPUser = 0;
	do
	{
		cout << "Enter Operation type [1] Add, [2] Subtract , [3] Multiplication , [4] Division , [5] Mix ? ";
		cin >> OPUser;
	} while (OPUser < 1 || OPUser >= 5);
	return (enMath)OPUser;
}

struct stQuestion {
	int Number1 = 0;
	int Number2 = 0;
	enMath Math;
	enLevel Level;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz {
	stQuestion QuestionList[100];
	short NumberOfQuestions;
	enLevel Level;
	enMath Math;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightanswers = 0;
	bool isPass = false;
};



enMath GetRandomOperationType() {
	int Op = RandomNumber(1, 4);
	return (enMath)Op;
}

stQuestion GenerateQuestion(enLevel QuestionLevel, enMath OpType) {
	stQuestion Question;

	if (QuestionLevel == enLevel::Mix) {
		QuestionLevel = (enLevel)RandomNumber(1, 3);
	}
	if (OpType == enMath::MixOP) {
		OpType == GetRandomOperationType();
	}

	Question.Math = OpType;

	switch (QuestionLevel)
	{
	case enLevel::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.Math);
		Question.Level = QuestionLevel;
		return Question;

	case enLevel::Medium:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.Math);
		Question.Level = QuestionLevel;
		return Question;

	case enLevel::Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.Math);
		Question.Level = QuestionLevel;
		return Question;
	}

	return Question;
}

void GenerateQuizzQestions(stQuizz& Quizz) {
	for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
		Quizz.QuestionList[Question] = GenerateQuestion(Quizz.Level, Quizz.Math);
	}
}




//int RandomMath() {
//	return RandomNumber(1,9);
//}
//
//enMath UserMath(int OPUser) {
//	switch (OPUser)
//	{
//	case 1: return enMath::Add;
//	case 2: return enMath::Subtract;
//	case 3: return enMath::Multiplication;
//	case 4: return enMath::Division;
//	}
//}

int ReadQuestionAnswer() {
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void PrintTheQuestion(stQuizz &Quizz, short QuestionNumber){
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].Math);
	cout << "\n_____________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber) {
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :-( \n";
		cout << "The right answer is: ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightanswers++;
		cout << "Right Answer :-) \n";
	}
	cout << endl;

	SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz) {
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {

		PrintTheQuestion(Quizz, QuestionNumber);

		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQuestionAnswer(Quizz, QuestionNumber);

		Quizz.isPass = (Quizz.NumberOfRightanswers >= Quizz.NumberOfWrongAnswers);
	}
}

string GetFinalResultsText(bool Pass) {
	if (Pass)
		return "Pass :-)";
	else
		return "Fail :-(";
}

void PrintQuizzResults(stQuizz Quizz) {
	cout << "\n";
	cout << "___________________________\n\n";
	cout << " Final Results is " << GetFinalResultsText(Quizz.isPass);
	cout << "\n_________________________\n\n";

	cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level    : " << GetQuestionLevelText(Quizz.Level) << endl;
	cout << "Operation Type     : " << GetOpTypeSymbol(Quizz.Math) << endl;
	cout << "Number of Rigth Answers: " << Quizz.NumberOfRightanswers << endl;
	cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "___________________________\n";

}

void PlayMathGame() {
	stQuizz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyQestions();
	Quizz.Level = ReadQuestionsLevel();
	Quizz.Math = ReadOperationType();

	GenerateQuizzQestions(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResults(Quizz);

}

void ResetScreen() {
	system("cls");
	system("color 0F");
}

void StartGame() {
	char PlayAgain = 'Y';
	do {
		ResetScreen();
		PlayMathGame();

		cout << endl << "Do you want to play again? Y/N ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
	srand((unsigned)time(NULL));
	

	StartGame();
	return 0;
}