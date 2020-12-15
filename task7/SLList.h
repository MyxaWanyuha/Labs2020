#pragma once
class SLList
{
public:
	static SLList* beginList(int data) { return new SLList(data); }
	int getData() const noexcept       { return m_data; }
	void setData(int data) noexcept    { m_data = data; }
	SLList* next() const noexcept	   { return m_nextElem; }
	bool hasNext() const noexcept	   { return m_nextElem; }
	SLList* addElement(int data) noexcept;

	void removeNext() noexcept;
	~SLList() { delete m_nextElem; }
	SLList()							 = delete;
	SLList(const SLList&)				 = delete;
	SLList(SLList&&) noexcept			 = delete;
	SLList& operator=(const SLList&)     = delete;
	SLList& operator=(SLList&&) noexcept = delete;
private:
	SLList(int data) : m_nextElem(nullptr), m_data(data) {};
	SLList* m_nextElem;
	int m_data;
};
