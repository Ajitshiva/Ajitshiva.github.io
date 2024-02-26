var relearn_search_index = [
  {
    "breadcrumb": "Kode Kaavalan",
    "content": "",
    "description": "",
    "tags": null,
    "title": "Categories",
    "uri": "/categories/index.html"
  },
  {
    "breadcrumb": "Kode Kaavalan",
    "content": "\rIdeas\rTemplates\rTricks\rLeft Aligned Center Aligned Right Aligned 1 Templates Click to view 2 Tricks Click to view 3 Ideas Click to view ",
    "description": "",
    "tags": null,
    "title": "Competitive Programming",
    "uri": "/competitive-programming/index.html"
  },
  {
    "breadcrumb": "Kode Kaavalan \u003e Competitive Programming",
    "content": "",
    "description": "",
    "tags": null,
    "title": "Ideas",
    "uri": "/competitive-programming/ideas/index.html"
  },
  {
    "breadcrumb": "",
    "content": "Are you passionate about programming, data structures, algorithms, and competitive coding? Look no further! Kode Kaavalan is your go-to destination for all things related to mastering programming challenges and honing your problem-solving skills.\nWhat Sets Us Apart Algorithmic Insights: Explore in-depth explanations and intuitive breakdowns of algorithmic concepts ranging from classic sorting and searching techniques to dynamic programming, graph algorithms, and beyond. Our blog is your gateway to understanding the intricate logic behind these algorithms, empowering you to tackle complex coding challenges with confidence.\nProgramming Contest Problems: Immerse yourself in a treasure trove of programming contest problems curated from leading platforms such as Codeforces, Codechef, LeetCode, and AtCoder. Each problem comes with a detailed analysis, providing valuable insights into problem-solving strategies and algorithmic approaches.\nComprehensive Tutorials: Whether you’re a beginner or an experienced coder, our comprehensive tutorials cater to all skill levels. From foundational concepts to advanced techniques, we cover everything you need to know to excel in competitive programming and beyond.\nInteractive Learning Experience: Engage with our content through interactive code examples, visualizations, and real-world applications. We believe in learning by doing, and our hands-on approach ensures that you not only understand algorithms and data structures but also how to apply them effectively in practice.\nThriving Community: Join our vibrant community of programming enthusiasts, where you can connect with like-minded individuals, share insights, and collaborate on solving challenging problems. Whether you’re seeking advice, discussing solutions, or simply celebrating your coding victories, you’ll find a supportive network ready to cheer you on.\nEmbark on Your Coding Journey Today!\nReady to embark on an exciting journey through the realms of algorithms, data structures, and competitive coding? Dive into our latest posts, tutorials, and problem-solving guides to elevate your programming skills to new heights. Whether you’re aiming for success in coding interviews, competitions, or personal projects, [Your Blog Name] is your trusted companion every step of the way.\nLet’s unravel the mysteries of algorithms, one problem at a time. Welcome to a world of endless possibilities, where curiosity meets creativity, and challenges become opportunities for growth. Join us on [Your Blog Name] and start coding your way to success!\n",
    "description": "",
    "tags": null,
    "title": "Kode Kaavalan",
    "uri": "/index.html"
  },
  {
    "breadcrumb": "Kode Kaavalan",
    "content": "",
    "description": "",
    "tags": null,
    "title": "Tags",
    "uri": "/tags/index.html"
  },
  {
    "breadcrumb": "Kode Kaavalan \u003e Competitive Programming",
    "content": " No Title Link 1 Union-Find Click to view ",
    "description": "",
    "tags": null,
    "title": "Templates",
    "uri": "/competitive-programming/templates/index.html"
  },
  {
    "breadcrumb": "Kode Kaavalan \u003e Competitive Programming",
    "content": "",
    "description": "",
    "tags": null,
    "title": "Tricks",
    "uri": "/competitive-programming/tricks/index.html"
  },
  {
    "breadcrumb": "Kode Kaavalan \u003e Competitive Programming \u003e Templates",
    "content": "\r​\rPython\rJava\rC++\rclass UnionFind: def __init__(self, n: int): self.root = list(range(n)) self.rank = [1 for _ in range(n)] self.rank[0] = 10 ** 5 + 1 def find(self, x: int) -\u003e int: if self.root[x] != x: self.root[x] = self.find(self.root[x]) return self.root[x] def union(self, x: int, y: int) -\u003e None: rootx, rooty = self.root[x], self.root[y] if rootx == rooty: return if self.rank[rootx] \u003e self.rank[rooty]: self.root[rooty] = rootx elif self.rank[rootx] \u003c self.rank[rooty]: self.root[rootx] = rooty else: self.root[rooty] = rootx self.rank[rootx] += 1 def is_connected(self, x: int, y: int) -\u003e bool: return self.find(x) == self.find(y) def reset(self, x: int) -\u003e None: self.root[x] = x self.rank[x] = 1\recho \"Hello World!\"\rprintf\"Hello World!\");\r",
    "description": "",
    "tags": null,
    "title": "Union Find",
    "uri": "/competitive-programming/templates/unionfind/index.html"
  }
]
