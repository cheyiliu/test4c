#ifndef __REF_H__
#define __REF_H__
class Ref
{
public:
	/**
	 * Retains the ownership.
	 *
	 * This increases the Ref's reference count.
	 *
	 * @see release, autorelease
	 * @js NA
	 */
	void retain();

	/**
	 * Releases the ownership immediately.
	 *
	 * This decrements the Ref's reference count.
	 *
	 * If the reference count reaches 0 after the descrement, this Ref is
	 * destructed.
	 *
	 * @see retain, autorelease
	 * @js NA
	 */
	void release();

	/**
	 * Returns the Ref's current reference count.
	 *
	 * @returns The Ref's reference count.
	 * @js NA
	 */
	unsigned int getReferenceCount() const;

protected:
	/**
	 * Constructor
	 *
	 * The Ref's reference count is 1 after construction.
	 * @js NA
	 */
	Ref();

public:
	/**
	 * @js NA
	 * @lua NA
	 */
	virtual ~Ref();

protected:
	/// count of references
	unsigned int _referenceCount;

};
#endif // __REF_H__
