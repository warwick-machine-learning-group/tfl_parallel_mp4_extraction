#ifndef _COMMONDATADEFS_H_
#define _COMMONDATADEFS_H_
/*****************************************************************************
 * Filename		: CommonDataDefs.h
 * Author		: Edward Chuah
 * Organisation	: The University of Warwick, UK.
 * Date Created	: 1 May 2020
 * Description	: Contain definitions for common data types.
 *			
 * Version				: See release notes.
 * Owner				: To be included.
 * Copyright(c) 2020	: To be included.
 * 
 * Change Log:
 * Date			Author				Change Description
 * ====         ======				==================
 * 
 ****************************************************************************/
#include <string>
#include <vector>
#include "opencv2/core/mat.hpp"

class VideoData;


namespace CommonDataDefs
{
	typedef int					IntT;
	typedef unsigned int		UIntT;
	typedef long				LongT;
	typedef long int			LongIntT;
	typedef unsigned long		ULongT;
	typedef unsigned long long 	ULLongT;
	typedef bool				BoolT;
	typedef float				FloatT;
	typedef double				DoubleT;
	typedef char				CharT;
	typedef unsigned char		UCharT;
	typedef std::string			StringT;
	typedef VideoData			VideoDataT;
	typedef cv::Mat				MatT;

	typedef std::vector< int >					IntVectorT;
	typedef std::vector< unsigned int >			UIntVectorT;
	typedef std::vector< long >					LongVectorT;
	typedef std::vector< long int >				LongIntVectorT;
	typedef std::vector< ULLongT >				ULLVectorT;
	typedef std::vector< float >				FloatVectorT;
	typedef std::vector< double >				DoubleVectorT;
	typedef std::vector< char >					CharVectorT;
	typedef std::vector< StringT >				StringVectorT;
	typedef std::vector< MatT >					MatVectorT;
	typedef std::vector< UCharT >				UCharVectorT;

	typedef std::vector< StringVectorT >		VectorOfStringVectorT;
	typedef std::vector< IntVectorT >			VectorOfIntVectorT;
	typedef std::vector< LongIntVectorT >		VectorOfLongIntVectorT;
	typedef std::vector< ULLVectorT >			VectorOfULLVectorT;
	typedef std::vector< FloatVectorT >			VectorOfFloatVectorT;
	typedef std::vector< DoubleVectorT >		VectorOfDoubleVectorT;
	typedef std::vector< VideoDataT >			VideoDataVectorT;
	typedef std::vector< UCharVectorT >			VectorOfUCharVectorT;

}; // end namespace CommonDataDefs.

#endif // _COMMONDATADEFS_H_
