#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "Post.h"

using namespace std;

class PaidUser : public User
{
	private:
		Post* _posts;
		int _postsCount;
	public:
		void SetPosts(Post*, int);

		Post* GetPosts();
		int GetPostsCount();
		//TODO: Константные ссылки? (+)
		PaidUser(int, const string&, const string&, Post*, int);
		//TODO: Константные ссылки? (+)
		PaidUser(int, const string&, const string&);
};