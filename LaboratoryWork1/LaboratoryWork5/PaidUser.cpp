#include "PaidUser.h"
#include "DoubleValidator.h"

void PaidUser::SetPosts(Post* posts, int postsCount)
{
	DoubleValidator::AssertPositiveValue(postsCount);
	_posts = posts;
	_postsCount = postsCount;
}

Post* PaidUser::GetPosts()
{
	return _posts;
}

int PaidUser::GetPostsCount()
{
	return _postsCount;
}

PaidUser::PaidUser(int id, const string& login, 
	const string& password, Post* posts, int postsCount)
	: User(id, login, password)
{
	SetPosts(posts, postsCount);
}

PaidUser::PaidUser(int id, const string& login, const string& password)
	: PaidUser(id, login, password, nullptr, 0)
{

}