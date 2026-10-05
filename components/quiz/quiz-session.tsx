'use client'

import { useEffect, useEffectEvent, useState } from 'react'
import { ArrowRight, Flame, X } from 'lucide-react'
import { Button } from '@/components/ui/button'
import { SECONDS_PER_QUESTION, type Category } from '@/lib/quiz-data'
import { QuestionCard } from './question-card'
import { TimerBar } from './timer-bar'
import type { AnswerRecord } from './quiz-results'

type Props = {
  category: Category
  onFinish: (answers: AnswerRecord[]) => void
  onQuit: () => void
}

function pointsFor(correct: boolean, timeLeft: number, streak: number) {
  if (!correct) return 0
  const speedBonus = Math.round((timeLeft / SECONDS_PER_QUESTION) * 50)
  const streakBonus = Math.min(streak, 5) * 10
  return 100 + speedBonus + streakBonus
}

export function QuizSession({ category, onFinish, onQuit }: Props) {
  const [index, setIndex] = useState(0)
  const [selected, setSelected] = useState<number | null>(null)
  const [revealed, setRevealed] = useState(false)
  const [timeLeft, setTimeLeft] = useState(SECONDS_PER_QUESTION)
  const [answers, setAnswers] = useState<AnswerRecord[]>([])
  const [streak, setStreak] = useState(0)

  const question = category.questions[index]
  const total = category.questions.length
  const isLast = index === total - 1
  const score = answers.reduce((sum, a) => sum + a.points, 0)

  const submit = (choice: number | null) => {
    if (revealed) return
    const correct = choice === question.answer
    const nextStreak = correct ? streak + 1 : 0
    setSelected(choice)
    setRevealed(true)
    setStreak(nextStreak)
    setAnswers((prev) => [
      ...prev,
      { question, selected: choice, correct, points: pointsFor(correct, timeLeft, nextStreak - 1) },
    ])
  }

  const next = () => {
    if (!revealed) return
    if (isLast) {
      onFinish(answers)
      return
    }
    setIndex((i) => i + 1)
    setSelected(null)
    setRevealed(false)
    setTimeLeft(SECONDS_PER_QUESTION)
  }

  const onTimeout = useEffectEvent(() => submit(null))

  useEffect(() => {
    if (revealed) return
    if (timeLeft <= 0) {
      onTimeout()
      return
    }
    const id = setTimeout(() => setTimeLeft((t) => t - 1), 1000)
    return () => clearTimeout(id)
  }, [timeLeft, revealed])

  const onKey = useEffectEvent((e: KeyboardEvent) => {
    if (e.metaKey || e.ctrlKey || e.altKey) return
    const n = Number(e.key)
    if (!revealed && n >= 1 && n <= question.options.length) {
      submit(n - 1)
    } else if (revealed && e.key === 'Enter') {
      e.preventDefault()
      next()
    }
  })

  useEffect(() => {
    const handler = (e: KeyboardEvent) => onKey(e)
    window.addEventListener('keydown', handler)
    return () => window.removeEventListener('keydown', handler)
  }, [])

  return (
    <div className="mx-auto flex w-full max-w-3xl flex-col gap-8 px-4 py-8 md:py-14">
      <header className="flex items-center justify-between gap-4">
        <Button variant="ghost" size="sm" onClick={onQuit} className="-ml-2 gap-1.5">
          <X className="size-4" aria-hidden="true" />
          {'Quit'}
        </Button>
        <p className="font-display text-lg font-bold">{category.name}</p>
        <div className="flex items-center gap-3">
          <span
            className={`flex items-center gap-1 rounded-full border-2 border-foreground px-2.5 py-0.5 text-sm font-bold transition-colors ${
              streak >= 2 ? 'bg-primary text-primary-foreground' : 'bg-card'
            }`}
            aria-label={`Streak: ${streak}`}
          >
            <Flame className="size-4" aria-hidden="true" />
            {streak}
          </span>
          <span className="font-display text-lg font-bold tabular-nums" aria-label={`Score: ${score}`}>
            {score}
          </span>
        </div>
      </header>

      <div className="flex flex-col gap-3">
        <div className="flex items-center justify-between text-sm font-medium">
          <span>{`Question ${index + 1} of ${total}`}</span>
          <span className="tabular-nums text-muted-foreground" aria-live="off">
            {revealed ? 'Time stopped' : `${timeLeft}s left`}
          </span>
        </div>
        <div className="flex gap-1.5" aria-hidden="true">
          {category.questions.map((q, i) => {
            const record = answers[i]
            const color = record
              ? record.correct
                ? 'bg-success'
                : 'bg-destructive'
              : i === index
                ? 'bg-foreground'
                : 'bg-foreground/15'
            return <span key={q.id} className={`h-2 flex-1 rounded-full transition-colors ${color}`} />
          })}
        </div>
        <TimerBar timeLeft={timeLeft} total={SECONDS_PER_QUESTION} paused={revealed} />
      </div>

      <QuestionCard
        key={question.id}
        question={question}
        selected={selected}
        revealed={revealed}
        onSelect={submit}
      />

      <div className="flex min-h-12 items-center justify-end">
        {revealed && (
          <Button size="lg" onClick={next} autoFocus className="h-12 gap-2 rounded-xl px-6 text-base">
            {isLast ? 'See results' : 'Next question'}
            <ArrowRight className="size-4" aria-hidden="true" />
          </Button>
        )}
      </div>
    </div>
  )
}
