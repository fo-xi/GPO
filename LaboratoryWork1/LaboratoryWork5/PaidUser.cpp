#include "PaidUser.h"
#include <exception> 

void PaidUser::SetPosts(Post* posts, int postsCount)
{
	if (postsCount < 0)
	{
		throw exception("The value cannot be negative");
	}
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